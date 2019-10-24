#include "CLD3.Net.h"
#include "Resource.h"

#include <string>

System::String^ CLD3Net::LanguageDetector::DetectLanguage(System::String^ text)
{	
	auto bytes = Encoding::UTF8->GetBytes(text);
	pin_ptr<Byte> pinnedBytes = &bytes[0];
	auto x = reinterpret_cast<char*>(pinnedBytes);
	std::string utf8NativeString(x);
	Result result = findLanguage(utf8NativeString);
	std::string language = result.language;
	//float probability = result.probability;
	//bool is_reliable=
	std::string jsonOut="";
	jsonOut = jsonOut.append("{\"language\":\"").append(codeToLangName[result.language]).append("\",\"probability\":").append(std::to_string(result.probability)).append(",\"is_reliable\":").append(std::to_string(result.is_reliable)).append(",\"proportion\":").append(std::to_string(result.proportion)).append("}");
	//{"language":"en", "probability" : 0.0, "is_reliable" : false, "proportion" : 0.0}
	return gcnew System::String(jsonOut.c_str());
}
System::String^ CLD3Net::LanguageDetector::DetectNMostFreqLangs(System::String^ text, int numberOfLangs)
{
	auto bytes = Encoding::UTF8->GetBytes(text);
	pin_ptr<Byte> pinnedBytes = &bytes[0];
	auto x = reinterpret_cast<char*>(pinnedBytes);
	std::string utf8NativeString(x);
	std::string jsonOut = "";
	if (numberOfLangs > 0) {
		if (numberOfLangs == 1) {
			Result result = findLanguage(utf8NativeString);
			std::string language = result.language;
			//float probability = result.probability;
			//bool is_reliable=
			
			jsonOut = jsonOut.append("{\"language\":\"").append(codeToLangName[result.language]).append("\",\"probability\":").append(std::to_string(result.probability)).append(",\"is_reliable\":").append(std::to_string(result.is_reliable)).append(",\"proportion\":").append(std::to_string(result.proportion)).append("}");
			//{"language":"en", "probability" : 0.0, "is_reliable" : false, "proportion" : 0.0}
			return gcnew System::String(jsonOut.c_str());
		}
		else {
			auto languages = findTopNMostFreqLangs(utf8NativeString, numberOfLangs);
			jsonOut = jsonOut.append("[");
			for (int i = 0; i < numberOfLangs; i++) {
				auto result = languages[i];
				std::string language = result.language;
				jsonOut = jsonOut.append("{\"language\":\"").append(result.language).append("\",\"probability\":").append(std::to_string(result.probability)).append(",\"is_reliable\":").append(std::to_string(result.is_reliable)).append(",\"proportion\":").append(std::to_string(result.proportion)).append("},");
				//{"language":"en", "probability" : 0.0, "is_reliable" : false, "proportion" : 0.0}
				
			}
			jsonOut.pop_back();
			jsonOut = jsonOut.append("]");
			return gcnew System::String(jsonOut.c_str());
			
		}
	}
	else {
		jsonOut = jsonOut.append("{}");
		return gcnew System::String(jsonOut.c_str());
	}
	
}

