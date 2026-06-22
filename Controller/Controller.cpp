#include "pch.h"
#include "Controller.h"

void Controller::Operations::Initialize() {
	//Console::WriteLine(GetMD5Hash("admin" + "1234"));	


	//if (Persistance::persistance::exists(UserFilePath)) {
	//	usuarios = (List<Usuario^> ^)Persistance::persistance::LoadDataFromText(UserFilePath, Usuario::typeid);
	//} 
	//else{
	//	usuarios->Add(gcnew Usuario("admin", "c93ccd78b2076528346216b3b2f701e6"));		
	//	Persistance::persistance::SaveDataToText(UserFilePath, usuarios);
	//}

	//if (Persistance::persistance::exists(UserXMLFilePath)) {
	//	usuarios = (List<Usuario^>^)Persistance::persistance::LoadDataFromXML(UserXMLFilePath, Usuario::typeid);
	//}
	//else {
	//	usuarios->Add(gcnew Usuario("admin", "c93ccd78b2076528346216b3b2f701e6"));
	//	Persistance::persistance::SaveDataToXML(UserXMLFilePath, usuarios);
	//}

	//if (Persistance::persistance::exists(UserBinaryFilePath)) {
	//	usuarios = (List<Usuario^>^)Persistance::persistance::LoadDataFromBinary (UserBinaryFilePath, Usuario::typeid);
	//}
	//else {
	//	usuarios->Add(gcnew Usuario("admin", "c93ccd78b2076528346216b3b2f701e6"));
	//	Persistance::persistance::SaveDataToBinary(UserBinaryFilePath, usuarios);
	//}

	if (Persistance::persistance::usersExistOnDatabase()) {
		usuarios = Persistance::persistance::getUsersSQL();
		for (int i = 0; i < usuarios->Count; i++) {
			Console::WriteLine("El usuarios es: " + usuarios[i]->Nombre);

		}
	}
	else {
		Persistance::persistance::addUserSQL("admin", "c93ccd78b2076528346216b3b2f701e6");
	}

}

void Controller::Operations::UpdateUser() {
	if (Persistance::persistance::usersExistOnDatabase()) {
		Console::WriteLine("Actualizando usuarios desde la base de datos");
		usuarios = Persistance::persistance::getUsersSQL();
	}
}

Usuario^ Controller::Operations::ReadUser(String^ user) {
	for(int i = 0; i < usuarios->Count; i++) {
		Console::WriteLine("El usuario es: -" + usuarios[i]->Nombre->Trim() + "-" + user + "-");
		if (usuarios[i]->Nombre->Trim() == user) {
			return usuarios[i];
		}
	}
	return nullptr;
}

Usuario^ Controller::Operations::CreateUser(String^ username, String^ password) {
	Usuario^ newUser = gcnew Usuario(username, Model::Utils::GetMD5Hash(username + password));
	usuarios->Add(newUser);
	//Persistance::persistance::SaveDataToText(UserFilePath, usuarios);
	int id_usuario = Persistance::persistance::addUserSQL(username, Model::Utils::GetMD5Hash(username + password));
	Console::WriteLine("El id del usuario es: {0}", id_usuario);
	return newUser;
}

Usuario^ Controller::Operations::UpdateUser(String^ username, String^ newusername, String^ password) {
	for(int i = 0; i < usuarios->Count; i++) {
		if (usuarios[i]->Nombre == username) {
			usuarios[i]->Nombre = newusername;

			usuarios[i]->Contrasena = Model::Utils::GetMD5Hash(newusername +password);
			return usuarios[i];
		}
	}
	return nullptr;
}

Usuario^ Controller::Operations::DeleteUser(String^ username) {
	for(int i = 0; i < usuarios->Count; i++) {
		if (usuarios[i]->Nombre == username) {
			Usuario^ deletedUser = usuarios[i];
			usuarios->RemoveAt(i);
			return deletedUser;
		}
	}
	return nullptr;
}

bool Controller::Operations::deleteUserSQL(int id) {
	return Persistance::persistance::deleteUserSQL(id);
}

bool Controller::Operations::updateUserSQL(int id, String^ username, String^ password) {
	return Persistance::persistance::updateUserSQL(id, Utils::GetMD5Hash(username + password));
}