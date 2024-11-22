#include "pch.h" 
#include "CppUnitTest.h" 
#include "../Lab_11.2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // Тестуємо функцію processLine для обробки одного рядка 
        TEST_METHOD(TestProcessLine)
        {
            // Вхідний рядок 
            const char inputLine[] = "Tes#t123 Str@ing";
            const char* expectedOutput = "Test  Str@ing"; // Очікуваний результат 
            // Буфер для результату обробки 
            const char* tempOutputFile = "temp_output.txt";
            // Запис результату в тимчасовий файл 
            std::ofstream outputFile(tempOutputFile);
            processLine(inputLine, outputFile);
            outputFile.close();
            // Зчитуємо результат з файлу 
            std::ifstream outputFileCheck(tempOutputFile);
            std::string result((std::istreambuf_iterator<char>(outputFileCheck)),
                std::istreambuf_iterator<char>());
            outputFileCheck.close();
            // Перевірка результату 
            Assert::AreEqual(std::string(expectedOutput), result);
        }
    };
}
