#pragma once
using namespace Model;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Xml::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::IO;
using namespace System::Data::SqlClient;

namespace Persistance {
	public ref class persistance
	{
	public:
		static String^ database = "poo20261";
		static String^ userDB = "poousuario";
		static String^ passwordDB = "4i5jp3tax7ys";
		static String^ serverName = "poo20261.c1cidnallaxc.us-east-1.rds.amazonaws.com";
		static bool exists(String^ filePath);


		static void SaveDataToText(String^ filePath, Object^ ObjectData);
		static Object^ LoadDataFromText(String^ filePath,Type^ tipo);

		static void SaveDataToXML(String^ filePath, Object^ ObjectData);
		static Object^ LoadDataFromXML(String^ filePath, Type^ tipo);
		
		static void SaveDataToBinary(String^ filePath, Object^ ObjectData);
		static Object^ LoadDataFromBinary(String^ filePath, Type^ tipo);

		static SqlConnection^ GetConnection();

		static int addUserSQL(String^ username, String^ password);
		static bool usersExistOnDatabase();
		static List<Usuario^>^ getUsersSQL();

	};
}
