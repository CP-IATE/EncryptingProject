#include <iostream>
#include <string>
using namespace std;

int main() {
  setlocale(LC_CTYPE, "ukr");

  cout << "Vvedit' rechenniа: ";
  string fraza;
  getline(cin, fraza);

  cout << "Vashe rechenniа: " << fraza << endl;

  int zmi;
  cout << "Napishit' zmіshchennia: ";
  cin >> zmi;

  const int bukv = fraza.size();
  string cipher = fraza;

  for (int i = 0; i < bukv; i++) {
    char c = fraza[i];

  
    if (isalpha(c)) {

      char number;
      if (isupper(c)) {
        number = 'A';
      }
      else {
        number = 'a';
      }
      c = number + (c - number + zmi) % 26; 

    cipher[i] = c;
  }

  cout << "Zashifrovane rechenniа: " << cipher << endl; 
  return 0;
}
