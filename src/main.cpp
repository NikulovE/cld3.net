#include "lIdentifier.hpp"
#include <algorithm>
#include <codecvt>
#include <iostream>
#include <locale>
#include <map>
#include <vector>

#ifdef __linux__
#define WMAIN main
#define WSTRING string
#define WCHAR char
#else
#define WMAIN wmain
#define WSTRING wstring
#define WCHAR wchar_t
#endif

using namespace std;


void runTopFrequent(const string& text, int numOfLangs);

clock_t startTime;


//working with the already defined WMAIN WCHAR gave me errors
#ifdef __linux__
int main(int argc, char* argv[])
#else
int wmain(int argc, wchar_t* argv[])
#endif
{
	if (argc < 2) {
		std::cout << "usage: blah blach " << argv[0] << endl;
		return 0;
	}
#ifdef __linux__
	std::string text(argv[1]);
#else
	std::wstring wText(argv[1]);
	 //see https://stackoverflow.com/a/18374698/4483033
	// use converter (.to_bytes: wstr->str, .from_bytes: str->wstr)
	std::string text =  std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(wText);
#endif // __linux__
	//std::string text(argv[1]);
	if (argc < 3) {
		Result result = findLanguage(text);
		std::cout << "text: " << text << std::endl
			<< "  language: " << result.language << std::endl
			<< "  language name: " << codeToLangName[result.language]
			<< std::endl
			<< "  probability: " << result.probability << std::endl
			<< "  reliable: " << result.is_reliable << std::endl
			<< "  proportion: " << result.proportion << std::endl
			<< std::endl;
		return 0;
	}
	int numOfLangs = stoi(argv[2]);
	runTopFrequent(text, numOfLangs);
	return 0;
}

void runTopFrequent(const string& text, int numOfLangs) {
	Result* results = new Result[numOfLangs];
	findTopNMostFreqLangs(text, numOfLangs, results);
	for (int i = 0; i < numOfLangs; i++) {
		auto result = results[i];
		std::cout << "  language code: " << result.language << std::endl
			<< "  language name: " << codeToLangName[result.language]
			<< std::endl
			<< "  probability: " << result.probability << std::endl
			<< "  reliable: " << result.is_reliable << std::endl
			<< "  proportion: " << result.proportion << std::endl
			<< std::endl;
	}
	delete[] results;
}