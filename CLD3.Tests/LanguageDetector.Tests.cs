using Newtonsoft.Json;
using System;

namespace CLD3.Tests
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestRussiaLanguage()
        {
            var detector = new CLD3Net.LanguageDetector();
            string? predictions = detector.DetectNMostFreqLangs("Привет, как дела?", 3);
            var Predictions=JsonConvert.DeserializeObject<List<Prediction>>(predictions);
            Assert.IsTrue(Predictions[0].language == "Russian");

        }

        [TestMethod]
        public void TestEnglishLanguage()
        {
            var detector = new CLD3Net.LanguageDetector();
            string? predictions = detector.DetectNMostFreqLangs("How are you?", 3);
            var Predictions = JsonConvert.DeserializeObject<List<Prediction>>(predictions);
            Assert.IsTrue(Predictions[0].language == "English");

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
