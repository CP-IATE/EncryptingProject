#pragma once

#include <string>
#include <windows.h>
#include <iostream>

using namespace std;

// Функція шифрування Цезаря
string Caesar(const string& LINE, const string& alphabet, int key) {
  string result = ""; 
  int len = alphabet.length();
  for (char b : LINE) {
    int num = alphabet.find(b);
    if (num != string::npos) {
      int new_index = (num + key + len) % len; 
      result += alphabet[new_index];
    }
    else {
      result += b; // Yakshcho symbol ne z alfavitu — dodai yogo bez zmin
    }
  }
  return result;
}

// Функція дешифрування (використовує ту ж саму Caesar, але з від’ємним ключем)
string Caesar2(const string& LINE, const string& alphabet, int key) {
  return Caesar(LINE, alphabet, -key);
}

// Головна функція виклику
void Execute1() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  int Key;
  string inputLINE;
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  cout << "Enter key: ";
  cin >> Key;
  cin.ignore(); 
  cout << "Enter word for encryption/decryption: ";
  getline(cin, inputLINE);
  for (char& c : inputLINE) {
    c = toupper(c);
  }

  // Шифрування
  string shifr = Caesar(inputLINE, alphabet, Key);
  cout << "\nEncrypted text: " << shifr << endl;

  // Дешифрування
  string deshifr = Caesar2(shifr, alphabet, Key);
  cout << "Decrypted text: " << deshifr << endl;
}
