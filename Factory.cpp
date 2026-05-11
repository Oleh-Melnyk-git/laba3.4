#include "Factory.h"

SymString *Factory::createSym(string id, string val) {
  return new SymString(id, val);
}

DecString *Factory::createDec(string id, string val) {
  return new DecString(id, val);
}

void Factory::destroy(SymString *obj) { delete obj; }
