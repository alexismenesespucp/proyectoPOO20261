#include "pch.h"

#include "Controller.h"

void Controller::Operations::Initialize() {
	//Console::WriteLine(GetMD5Hash("admin" + "1234"));	
	usuarios->Add(gcnew Usuario("admin", "c93ccd78b2076528346216b3b2f701e6"));
}

Usuario^ Controller::Operations::ReadUser(String^ user) {
	for(int i = 0; i < usuarios->Count; i++) {
		if (usuarios[i]->Nombre == user) {
			return usuarios[i];
		}
	}
	return nullptr;
}

Usuario^ Controller::Operations::CreateUser(String^ username, String^ password) {
	Usuario^ newUser = gcnew Usuario(username, Model::Utils::GetMD5Hash(username + password));
	usuarios->Add(newUser);
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