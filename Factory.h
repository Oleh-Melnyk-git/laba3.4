#ifndef FACTORY_H
#define FACTORY_H

#include "DecString.h"
#include "SymString.h"

class Factory {
public:
  static SymString *createSym(string id, string val);
  static DecString *createDec(string id, string val);
  static void destroy(SymString *obj);
};

#endif
