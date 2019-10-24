#pragma once

using namespace System;
using namespace System::Text;

namespace CLD3Net {
	public ref class LanguageDetector
	{
	public:
		String^ DetectLanguage(String^ text);
	public:
		String^ DetectNMostFreqLangs(String^ text, int numberOfLangs);
	};

}
