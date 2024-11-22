#include <iostream> 
#include <fstream> 
#include <cctype>  
#include <cstring> 
#include <Windows.h> 
using namespace std; 
// ������� ������� �����: ������� �� �������, �� �� � �������, �� ������� ������ 
void processLine(const char* line, ofstream& outputFile) { 
    int i = 0; 
    // ��������� �� ������� ������� �� ������� ������ ��� ���� ����� 
    while (line[i] != '\0' && line[i] != ' ') { 
        // ���� ������ � ������, �������� ���� � �������� ���� 
        if (isalpha(line[i])) { 
            outputFile.put(line[i]); 
        } 
        i++; 
    } 
    // ������ �����, ���� �� ��������� 
    if (line[i] == ' ') { 
        outputFile.put(' '); 
    } 
    // �������� ����� ����� ��� ��� 
      outputFile << &line[i]; // ���������� ������ ����� ��� � �� ���� �� �� ���� + 1 �� ������ line 
} 
int main() { 
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    const char* inputFileName = "t1.txt";  // ��'� �������� ����� 
    const char* outputFileName = "t2.txt"; // ��'� ��������� ����� 
    ifstream inputFile(inputFileName);    // ³�������� ������� ���� 
    ofstream outputFile(outputFileName);  // ³�������� �������� ���� 
    // �������� �� ������� �������� ����� 
    if (!inputFile.is_open()) { 
        cerr << "������� �������� �������� �����!" << endl; 
        return 1; 
    } 
    if (!outputFile.is_open()) { 
        cerr << "������� �������� ��������� �����!" << endl; 
        return 1; 
    } 
    char line[1024]; // ����� ��� ��������� ����� 
    // ������ ����� ����� �� �������� ����� � ���������� 
    while (inputFile.getline(line, sizeof(line))) { 
        processLine(line, outputFile); 
        outputFile.put('\n'); // ���������� �� ����� ����� � ��������� ���� 
    } 
    // ��������� ����� 
    inputFile.close(); 
    outputFile.close(); 
    cout << "������� ���������. ��������� �������� � ���� " << outputFileName << endl; 
    return 0; 
}
