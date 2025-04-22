#pragma once

#include <string>
#include <windows.h>
#include <iostream>

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

void Execute1() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice, Key;
    string inputLINE;
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    cout << "Enter option what do you want to do encryption(1)\t decryption(2)" << endl;
    cin >> choice;
    cout << "Enter key" << endl;
    cin >> Key;
    cin.ignore(); // Очищення буфера вводу перед getline()

    cout << "Enter word for encryption/decryption";
    getline(cin, inputLINE);

    if (choice == 1) {
        string shifr = Caesar(inputLINE, alphabet, Key);
        cout << shifr;
 
    }
    else if (choice == 2) {
        string deshifr = Caesar(inputLINE, alphabet, -Key);
        cout << deshifr;
}

