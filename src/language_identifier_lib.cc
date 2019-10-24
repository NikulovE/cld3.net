#define _CRT_SECURE_NO_WARNINGS
/* Copyright 2016 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include <iostream>
#include <map>
#include <locale>
#include <codecvt>
#include <string>
#include <Windows.h>

#include "base.h"
#include "nnet_language_identifier.h"

using chrome_lang_id::NNetLanguageIdentifier;

using namespace std;
#ifdef __linux__
#define EXPORT __attribute__((visibility("default")))
#else
#if defined(_MSC_VER)
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__((visibility("default")))
#endif
#endif

NNetLanguageIdentifier* lang_id = new NNetLanguageIdentifier(0, 4000);

// Min:
// Minimum number of bytes needed to make a prediction. If the default
// constructor is called, this variable is equal to kMinNumBytesToConsider.
// Max:
// Maximum number of bytes to use to make a prediction. If the default
// constructor is called, this variable is equal to kMaxNumBytesToConsider.
EXPORT void setMinMaxBytes(int min, int max) {
	delete lang_id;
	lang_id = new NNetLanguageIdentifier(min, max);
}

// @arr assumed to be be a pointer to an array with the size of @numberOfLangs
void findTopNMostFreqLangs(const string& text, int numberOfLangs,NNetLanguageIdentifier::Result* arr) {
	auto results = lang_id->FindTopNMostFreqLangs(text, numberOfLangs);
	std::copy(results.begin(), results.end(), arr);
}

EXPORT NNetLanguageIdentifier::Result* findTopNMostFreqLangs(const string& text, int numberOfLangs) {
	auto results = lang_id->FindTopNMostFreqLangs(text, numberOfLangs);
	NNetLanguageIdentifier::Result* arr = new NNetLanguageIdentifier::Result[numberOfLangs];
	findTopNMostFreqLangs(text, numberOfLangs, arr);
	return arr;
}

EXPORT NNetLanguageIdentifier::Result findLanguage(const string& text) {
	return lang_id->FindLanguage(text);
}

