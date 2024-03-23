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
    "language": "Russian",
    "probability": 0.977100,
    "is_reliable": 1,
    "proportion": 0.612245
  },
  {
    "language": "English",
    "probability": 0.998582,
    "is_reliable": 1,
    "proportion": 0.387755
  },
  {
    "language": "Undefined Language",
    "probability": 0.000000,
    "is_reliable": 0,
    "proportion": 0.000000
  }
]

Sample in .NetCoreApp:
```csharp
public static void Main(string[] args)
{
    var detector = new LanguageDetectorLibrary();
    var Rulanguage=detector.DetectLanguages("Привет, как дела?", 3);
    var Enlanguage=detector.DetectLanguages("How are you?", 3);
}