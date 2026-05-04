#pragma once
using namespace Model;
using namespace Persistance;
using namespace System;
using namespace System::Collections::Generic;

#define UserFilePath "users.txt"

namespace Controller {
	public ref class Operations
	{
		public:
			static List<Usuario^>^ usuarios = gcnew List<Usuario^>();
			static void Initialize();
			static Usuario^ ReadUser(String^ user);
			static Usuario^ CreateUser(String^ username, String^ password);
			static Usuario^ UpdateUser(String^ username, String^ newusername, String^ password);
			static Usuario^ DeleteUser(String^ username);
			
	};
}
