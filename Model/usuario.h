#pragma once

using namespace System;

namespace Model {
	public ref class Usuario
	{
	public:
		String^ Nombre;
		String^ Contrasena;
		String^ veriticationToken;
		Usuario(String^ nombre, String^ contrasena);
		void setTokenVerification(String^ token);
		bool autentificar();

	};
}