#pragma once

using namespace System;

namespace Model {
	public ref class Usuario
	{
	public:
		String^ Nombre;
		String^ Contrasena;
		String^ veriticationToken;
		Usuario(String^ nombre, String^ token);
		bool autentificar(String^ contrasena);

	};
}