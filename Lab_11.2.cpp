#include <iostream> 
#include <fstream> 
#include <cctype>  
#include <cstring> 
#include <Windows.h> 
using namespace std; 
// Функція обробки рядка: видаляє всі символи, які не є буквами, до першого пробілу 
void processLine(const char* line, ofstream& outputFile) { 
    int i = 0; 
    // Проходимо по кожному символу до першого пробілу або кінця рядка 
    while (line[i] != '\0' && line[i] != ' ') { 
        // Якщо символ є літерою, записуємо його у вихідний файл 
        if (isalpha(line[i])) { 
            outputFile.put(line[i]); 
        } 
        i++; 
    } 
    // Додаємо пробіл, якщо він знайдений 
    if (line[i] == ' ') { 
        outputFile.put(' '); 
    } 
    // Записуємо решту рядка без змін 
      outputFile << &line[i]; // Пропускаємо перший пробіл тут я не знаю чи має бути + 1 чи просто line 
} 
int main() { 
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    const char* inputFileName = "t1.txt";  // Ім'я вхідного файлу 
    const char* outputFileName = "t2.txt"; // Ім'я вихідного файлу 
    ifstream inputFile(inputFileName);    // Відкриваємо вхідний файл 
    ofstream outputFile(outputFileName);  // Відкриваємо вихідний файл 
    // Перевірка на помилки відкриття файлів 
    if (!inputFile.is_open()) { 
        cerr << "Помилка відкриття вхідного файлу!" << endl; 
        return 1; 
    } 
    if (!outputFile.is_open()) { 
        cerr << "Помилка відкриття вихідного файлу!" << endl; 
        return 1; 
    } 
    char line[1024]; // Буфер для зберігання рядка 
    // Читаємо кожен рядок із вхідного файлу і обробляємо 
    while (inputFile.getline(line, sizeof(line))) { 
        processLine(line, outputFile); 
        outputFile.put('\n'); // Переходимо на новий рядок у вихідному файлі 
    } 
    // Закриваємо файли 
    inputFile.close(); 
    outputFile.close(); 
    cout << "Обробка завершена. Результат записано у файл " << outputFileName << endl; 
    return 0; 
}
