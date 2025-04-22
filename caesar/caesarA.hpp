#pragma once

#include <string>
#include <windows.h>
#include <iostream>

using namespace std;

// Функція шифрування Цезаря
string Caesar(const string& LINE, const string& alphabet, int key) {
	string result = "";
	int len = alphabet.length();
	for (int i = 0; i<LINE.length(); i++) {
		char b = LINE[i];
		int num = alphabet.find(b);
		if (num != string::npos) {
			int new_index = (num + key) % len;
			if (new_index < 0) {
				new_index += len;
			}
			printf("\n%c-%d-%d", b, num, new_index);
			char e = alphabet[new_index];
			result += e;
			printf("-%c", e);
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
	int choice=1, Key;
	string inputLINE;
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	cout << "Enter key: ";
	cin >> Key;
	cin.ignore();
	cout << "Enter word for encryption/decryption: ";
	cin>>inputLINE;

	if (choice == 1) {
		string shifr = Caesar(inputLINE, alphabet, Key);
		cout << "\n" << shifr;

	}
	else if (choice == 2) {
		string deshifr = Caesar(inputLINE, alphabet, -Key);
		cout <<"\n" << deshifr;
	}
}

