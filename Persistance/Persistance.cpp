#include "pch.h"
#include "Persistance.h"
using namespace System::IO;

bool Persistance::persistance::exists(String^ filePath) {
	return File::Exists(filePath);
}

void Persistance::persistance::SaveDataToText(String^ filePath, Object^ ObjectData) {
	FileStream^ fileStream = nullptr;
	StreamWriter^ writer = nullptr;
	try {
		fileStream = gcnew FileStream(filePath, FileMode::Create, FileAccess::Write);
		writer = gcnew StreamWriter(fileStream);
		if (ObjectData != nullptr && ObjectData->GetType() == List<Usuario^>::typeid) {
			List<Usuario^>^ users = (List<Usuario^>^)ObjectData;
			for (int i = 0; i < users->Count; i++) {
				Usuario^ user = users[i];
				writer->WriteLine("{0}|{1}", user->Nombre, user->veriticationToken);
			}
		}

	}
	catch (Exception^ ex) {
		Console::WriteLine("Error saving data: " + ex->Message);
	}
	finally {
		if (writer != nullptr) {
			writer->Close();
		}
		if (fileStream != nullptr) {
			fileStream->Close();
		}
	}

}

Object^ Persistance::persistance::LoadDataFromText(String^ filePath, Type^ tipo) {
	FileStream^ fileStream = nullptr;
	StreamReader^ reader = nullptr;
	Object^ result;
	try {
		fileStream = gcnew FileStream(filePath, FileMode::Open, FileAccess::Read);
		reader = gcnew StreamReader(fileStream);
		if (tipo == Usuario::typeid) {
			result = gcnew List<Usuario^>();
			while (!reader->EndOfStream) {
				String^ line = reader->ReadLine();
				array<String^>^ records = line->Split('|');
				Usuario^ user = gcnew Usuario(records[0], records[1]);
				((List<Usuario^>^) result)->Add(user);
				}

			}
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error loading data: " + ex->Message);
	}
	finally {
		if (reader != nullptr) {
			reader->Close();
		}
		if (fileStream != nullptr) {
			fileStream->Close();
		}
	}

	return result;

}

void Persistance::persistance::SaveDataToXML(String^ filePath, Object^ ObjectData) {
	StreamWriter^ writer = nullptr;
	try {
		if(ObjectData != nullptr && ObjectData->GetType() == List<Usuario^>::typeid) {
			List<Usuario^>^ users = (List<Usuario^>^)ObjectData;

			writer = gcnew StreamWriter(filePath);
			XmlSerializer^ serializer = gcnew XmlSerializer(List<Usuario^>::typeid);
			serializer->Serialize(writer, users);
		}

	}
	catch (Exception^ ex) {
		Console::WriteLine("Error saving data to XML: " + ex->Message);
	}
	finally {
		if (writer != nullptr) {
			writer->Close();
		}
	}

}

Object^ Persistance::persistance::LoadDataFromXML(String^ filePath, Type^ tipo) {
	StreamReader^ reader = nullptr;
	Object^ result;
	XmlSerializer^ serializer = nullptr;
	try {
		if (tipo == Usuario::typeid) {
			reader = gcnew StreamReader(filePath);
			serializer = gcnew XmlSerializer(List<Usuario^>::typeid);
			result = serializer->Deserialize(reader);
		}
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error loading data from XML: " + ex->Message);
	}
	finally {
		if (reader != nullptr) {
			reader->Close();
		}
	}

	return result;

}

void Persistance::persistance::SaveDataToBinary(String^ filePath, Object^ ObjectData) {
	FileStream^ fileStream = nullptr;
	BinaryFormatter^ formatter = nullptr;
	try {
		fileStream = gcnew FileStream(filePath, FileMode::Create, FileAccess::Write);
		formatter = gcnew BinaryFormatter();
		formatter->Serialize(fileStream, ObjectData);
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error saving data to binary: " + ex->Message);
	}
	finally {
		if (fileStream != nullptr) {
			fileStream->Close();
		}
	}
}

Object^ Persistance::persistance::LoadDataFromBinary(String^ filePath, Type^ tipo) {
	FileStream^ fileStream = nullptr;
	BinaryFormatter^ formatter = nullptr;
	Object^ result;
	try {
		fileStream = gcnew FileStream(filePath, FileMode::Open, FileAccess::Read);
		formatter = gcnew BinaryFormatter();
		result = formatter->Deserialize(fileStream);
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error loading data from binary: " + ex->Message);
	}
	finally {
		if (fileStream != nullptr) {
			fileStream->Close();
		}
	}
	return result;
}

SqlConnection^ Persistance::persistance::GetConnection() {
	SqlConnection^ conn = gcnew SqlConnection();
	//String^ database = "login_app";
	//String^ userid = "proyectopoo";
	//String^ password = "12345678";
	//String^ serverName = "localhost\\SQLEXPRESS";
	
	conn->ConnectionString = String::Format("Server={0}; Database={1}; User ID={2}; Password={3};", serverName, database, userDB, passwordDB);
	try{
		conn->Open();
	}
	catch(Exception ^ ex) {
		Console::WriteLine("Error connecting to: " + conn->ConnectionString);
		Console::WriteLine("Error connecting to SQL: " + ex->Message);
	}
	return conn;
}

int Persistance::persistance::addUserSQL(String^ username, String^ password) {
	int result = -1;
	SqlConnection^ conn = nullptr;
	SqlCommand^ cmd = nullptr;
	try {
		conn = GetConnection();
		//cmd = gcnew SqlCommand("INSERT INTO login (usuario, password) VALUES (@user, @password)", conn);
		String^ procedure = "dbo.add_user";
		cmd = gcnew SqlCommand(procedure, conn);
		cmd->CommandType = System::Data::CommandType::StoredProcedure;
		cmd->Parameters->AddWithValue("@user", username);
		cmd->Parameters->AddWithValue("@password", password);
		//result = cmd->ExecuteNonQuery();
		Object^ objId = cmd->ExecuteScalar();
		Console::WriteLine("Result of ExecuteScalar: " + (objId != nullptr ? objId->ToString() : "null"));
		if (objId != nullptr && objId != DBNull::Value) {
			result = Convert::ToInt32(objId);
		}
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error adding user to SQL: " + ex->Message);
	}
	finally {
		if (cmd != nullptr) {
			delete cmd;
		}
		if (conn != nullptr) {
			conn->Close();
			delete conn;
		}
	}
	return result;
}

bool Persistance::persistance::usersExistOnDatabase() {
	bool exists = false;
	SqlConnection^ conn = nullptr;
	SqlCommand^ cmd = nullptr;
	SqlDataReader^ reader = nullptr;
	try {
		conn = GetConnection();
		cmd = gcnew SqlCommand("SELECT COUNT(*) FROM login", conn);
		int count = (int)cmd->ExecuteScalar();
		exists = count > 0;
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error checking users in SQL: " + ex->Message);
	}
	finally {
		if (reader != nullptr) {
			reader->Close();
		}
		if (cmd != nullptr) {
			delete cmd;
		}
		if (conn != nullptr) {
			conn->Close();
			delete conn;
		}
	}
	return exists;
}

bool Persistance::persistance::deleteUserSQL(int id) {
	int result = -1;
	SqlConnection^ conn = nullptr;
	SqlCommand^ cmd = nullptr;
	try {
		conn = GetConnection();
		String^ procedure = "dbo.delete_user";
		cmd = gcnew SqlCommand(procedure, conn);
		cmd->CommandType = System::Data::CommandType::StoredProcedure;
		cmd->Parameters->AddWithValue("@user", id);
		int resultado = Convert::ToInt32(cmd->ExecuteScalar());
		if (resultado == 1) {
			Console::WriteLine("Se eliminó el usuario correctamente");
			return true;
		}
		else {
			Console::WriteLine("No se eliminó el usuario");
		}
	}
	catch(Exception ^ ex) {
		Console::WriteLine("No se pudo eliminar el usuario " + ex->Message);
		return false;
	}
	
	return true;
}

bool Persistance::persistance::updateUserSQL(int id, String^ password) {
	int result = -1;
	SqlConnection^ conn = nullptr;
	SqlCommand^ cmd = nullptr;
	try {
		conn = GetConnection();
		String^ procedure = "dbo.update_user";
		cmd = gcnew SqlCommand(procedure, conn);
		cmd->CommandType = System::Data::CommandType::StoredProcedure;
		cmd->Parameters->AddWithValue("@user", id);
		cmd->Parameters->AddWithValue("@NewPassword", password);

		int resultado = Convert::ToInt32(cmd->ExecuteScalar());
		if (resultado == 1) {
			Console::WriteLine("Se eliminó el usuario correctamente");
			return true;
		}
		else {
			Console::WriteLine("No se eliminó el usuario");
		}
	}
	catch (Exception^ ex) {
		Console::WriteLine("No se pudo eliminar el usuario " + ex->Message);
		return false;
	}

	return true;
}

List<Usuario^> ^ Persistance::persistance::getUsersSQL() {
	List<Usuario^>^ users = gcnew List<Usuario^>();
	SqlConnection^ conn = nullptr;
	SqlCommand^ cmd = nullptr;
	SqlDataReader^ reader = nullptr;
	try {
		conn = GetConnection();
		cmd = gcnew SqlCommand("SELECT id, usuario, password FROM login", conn);
		reader = cmd->ExecuteReader();
		while (reader->Read()) {
			int id = reader->GetInt32(0);
			String^ username = reader->GetString(1);
			String^ password = reader->GetString(2);
			users->Add(gcnew Usuario(id, username, password));
		}
	}
	catch (Exception^ ex) {
		Console::WriteLine("Error getting users from SQL: " + ex->Message);
	}
	finally {
		if (reader != nullptr) {
			reader->Close();
		}
		if (cmd != nullptr) {
			delete cmd;
		}
		if (conn != nullptr) {
			conn->Close();
			delete conn;
		}
	}
	return users;
}