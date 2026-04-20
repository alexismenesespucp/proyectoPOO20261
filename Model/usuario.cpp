#include "pch.h"
#include "usuario.h"
#include "utils.h"

using namespace System;
using namespace Model;

Model::Usuario::Usuario(String^ nombre, String^ contrasena) {
	this->Nombre = nombre;
	this->Contrasena = contrasena;
}

void Model::Usuario::setTokenVerification(String^ token ) {
	this->veriticationToken = token;
	Console::WriteLine("Token de verificación generado: " + this->veriticationToken);
};

bool Model::Usuario::autentificar() {
	if(this->veriticationToken == Model::Utils::GetMD5Hash(this->Nombre + this->Contrasena)) {
		Console::WriteLine("Autenticación exitosa para el usuario: " + this->Nombre);
		return true;
	}
	else {
		Console::WriteLine("Autenticación fallida para el usuario: " + this->Nombre);
		return false;
	}
}