#ifndef SYMSTRING_H
#define SYMSTRING_H

#include <string>
using namespace std;

class SymString {
protected:
  string id;
  string value;

public:
  SymString(string id, string val);
  virtual ~SymString();
  virtual void Show();
  friend SymString operator+(SymString &s1, SymString &s2);
};

#endif
