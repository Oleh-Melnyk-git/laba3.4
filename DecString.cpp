#include "DecString.h"
#include <iostream>
using namespace std;

DecString::DecString(string id, string val) : SymString(id, val) {}

int DecString::toDecimal() { return stoi(value); }

void DecString::Show() {
  cout << "ID: " << id << " Decimal: " << value << endl;
}

void DecString::ShowOct() {
  int num = toDecimal();
  cout << "Octal: " << std::oct << num << endl;
  cout << std::dec; // Reset back to decimal format
}

DecString operator+(DecString &d1, DecString &d2) {
  int sum = d1.toDecimal() + d2.toDecimal();
  return DecString("result", to_string(sum));
}
