#include "pch.h" 
#include "CppUnitTest.h" 
#include "../Lab_11.2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // ������� ������� processLine ��� ������� ������ ����� 
        TEST_METHOD(TestProcessLine)
        {
            // ������� ����� 
            const char inputLine[] = "Tes#t123 Str@ing";
            const char* expectedOutput = "Test  Str@ing"; // ���������� ��������� 
            // ����� ��� ���������� ������� 
            const char* tempOutputFile = "temp_output.txt";
            // ����� ���������� � ���������� ���� 
            std::ofstream outputFile(tempOutputFile);
            processLine(inputLine, outputFile);
            outputFile.close();
            // ������� ��������� � ����� 
            std::ifstream outputFileCheck(tempOutputFile);
            std::string result((std::istreambuf_iterator<char>(outputFileCheck)),
                std::istreambuf_iterator<char>());
            outputFileCheck.close();
            // �������� ���������� 
            Assert::AreEqual(std::string(expectedOutput), result);
        }
    };
}
