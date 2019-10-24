using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace CLD3Tests
{
    [TestClass]
    public class LangugaTests
    {
        [TestMethod]
        public void TestMethod1()
        {
            var detector = new CLD3Net.LanguageDetector();
            var lang = detector.DetectNMostFreqLangs("Hello, how are you? Привет, как дела?", 4);
            Assert.IsTrue(lang == "ru");

        }
    }
}
