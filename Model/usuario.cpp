#include "pch.h"
#include "usuario.h"
#include "utils.h"

using namespace System;
using namespace Model;

Model::Usuario::Usuario() {
	this->Nombre = "";
	this->Contrasena = "";
	this->veriticationToken = "";
}

Model::Usuario::Usuario(String^ nombre, String^ token) {
	this->Nombre = nombre;
	this->veriticationToken = token;
}

Model::Usuario::Usuario(int id, String^ nombre, String^ token) {
	this->id = id;
	this->Nombre = nombre->Trim();
	this->veriticationToken = token;
}

bool Model::Usuario::autentificar(String^ contrasena) {
	this->Contrasena = contrasena;
	if(this->veriticationToken == Model::Utils::GetMD5Hash(this->Nombre + this->Contrasena)) {
		Console::WriteLine("Autenticación exitosa para el usuario: " + this->Nombre);
		return true;
	}
	else {
		Console::WriteLine("Autenticación fallida para el usuario: " + this->Nombre);
		return false;
	}
}