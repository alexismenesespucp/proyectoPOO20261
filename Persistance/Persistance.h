#pragma once
using namespace Model;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Xml::Serialization;
using namespace System::IO;

namespace Persistance {
	public ref class persistance
	{
	public:
		static bool exists(String^ filePath);

		static void SaveDataToText(String^ filePath, Object^ ObjectData);
		static Object^ LoadDataFromText(String^ filePath,Type^ tipo);

		static void SaveDataToXML(String^ filePath, Object^ ObjectData);
		static Object^ LoadDataFromXML(String^ filePath, Type^ tipo);


	};
}
