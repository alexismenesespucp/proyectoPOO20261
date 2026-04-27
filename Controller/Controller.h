#pragma once
using namespace Model;
using namespace System;
using namespace System::Collections::Generic;

namespace Controller {
	public ref class Operations
	{
		public:
			static List<Usuario^>^ usuarios = gcnew List<Usuario^>();
			static void Initialize();
			static Usuario^ ReadUser(String^ user);
			static Usuario^ CreateUser(String^ username, String^ password);
			static void UpdateUser(String^ username, String^ password);
			static Usuario^ DeleteUser(String^ username);
			
	};
}
