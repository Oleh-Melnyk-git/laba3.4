#ifndef DECSTRING_H
#define DECSTRING_H

#include "SymString.h"

class DecString : public SymString {
public:
  DecString(string id, string val);
  int toDecimal();
  void Show() override;
  void ShowOct();
  friend DecString operator+(DecString &d1, DecString &d2);
};

#endif
