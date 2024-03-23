using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using CLD3Net;

namespace CLD3NetCore
{
    public class LanguageDetectorLibrary
    {
        private LanguageDetector detector;

        public LanguageDetectorLibrary()
        {
            detector = new LanguageDetector();
        }

        public List<Prediction> DetectLanguages(string text, int numberOfLanguages)
        {
            string? predictions = detector.DetectNMostFreqLangs(text, numberOfLanguages);
            var Predictions = JsonConvert.DeserializeObject<List<Prediction>>(predictions);
            return Predictions;
        }
    }

    public class Prediction
    {
        public string language { get; set; }
        public float probability { get; set; }
        public int is_reliable { get; set; }
        public float proportion { get; set; }
    }
}
