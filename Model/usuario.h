#pragma once

using namespace System;

namespace Model {
	[Serializable]
	public ref class Usuario
	{
	public:
		String^ Nombre;
		String^ Contrasena;
		String^ veriticationToken;
		Usuario();
		Usuario(String^ nombre, String^ token);
		bool autentificar(String^ contrasena);

	};
}