# cld3.net
Compact language detector v3 by Google for .Net
<br>
in upstream google CLD3 https://github.com/google/cld3
<br>
thanks ezra100 for library https://gist.github.com/ezra100/ba69ec42600b2baa7430dd53bec3f37c
<p>
<br>
To solve issue with angle-brackets in headers extract google.zip (headers) to 
C:\Program Files (x86)\Microsoft Visual Studio\2019\%VSversion%\VC\Tools\MSVC\%msvcversion%\include
<br>
by default project configured for VS2019 .net 4.6.1

Detect for 3 possible languages:
```csharp
var detector = new CLD3Net.LanguageDetector();
var languges = detector.DetectNMostFreqLangs("Hello, how are you? Привет, как дела?", 3);
```
```json
[
  {
    "language": "ru",
    "probability": 0.9771,
    "is_reliable": 1,
    "proportion": 0.612245
  },
  {
    "language": "en",
    "probability": 0.998582,
    "is_reliable": 1,
    "proportion": 0.387755
  },
  {
    "language": "und",
    "probability": 0,
    "is_reliable": 0,
    "proportion": 0
  }
]
```
Detect language:
```csharp
var detector = new CLD3Net.LanguageDetector();
var lang = detector.DetectLanguage("Hello, how are you? Привет, как дела?");
```
```json
{
  "language": "en",
  "probability": 0.855358,
  "is_reliable": 1,
  "proportion": 1
}
```
