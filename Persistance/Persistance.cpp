#include "pch.h"
#include "Persistance.h"


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