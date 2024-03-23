using System;
using System.Collections.Generic;
using CLD3NetCore;

namespace LanguageDetectionApp
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var detector = new LanguageDetectorLibrary();
            var Rulanguage=detector.DetectLanguages("Привет, как дела?", 3);
            var Enlanguage=detector.DetectLanguages("How are you?", 3);
        }

    }
}
