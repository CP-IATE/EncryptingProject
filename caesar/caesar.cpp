#include <string>
#include <windows.h>
using namespace std;

string Caesar(const string& LINE, const string& alphabet, int key) {
    string result = ""; // Змінна для збереження результату
    for (char b : LINE) {
        int num = alphabet.find(b);
        if (num != string::npos) { // Перевіряємо, чи є символ у алфавіті
            int new_index = (num + key) % alphabet.length();
            result += alphabet[new_index];
        }
        else {
            result += b; // Якщо символ не знайдено, додаємо його без змін
        }
    }
    return result;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice, Key;
    string inputLINE;
    string alphabet = "АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";

    cout << "Введіть функцію яку бажаєте виконати шифрування(1)\t розшифрування(2)" << endl;
    cin >> choice;
    cout << "Введіть ключ" << endl;
    cin >> Key;
    cin.ignore(); // Очищення буфера вводу перед getline()

    cout << "Введіть елемент для шифрування/розшифрування ";
    getline(cin, inputLINE);

    if (choice == 1) {
        string shifr = Caesar(inputLINE, alphabet, Key);
        cout << shifr;
    }
}

