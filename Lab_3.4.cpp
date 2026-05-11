#include "Factory.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<SymString *> objects;
  int choice;

  do {
    cout << "\n--- MENU ---";
    cout << "\n1. Create SymString (Text)";
    cout << "\n2. Create DecString (Numbers)";
    cout << "\n3. Show all";
    cout << "\n4. Show Octal (only for numbers)";
    cout << "\n5. Add last two objects";
    cout << "\n6. Delete last";
    cout << "\n0. Exit";
    cout << "\nChoice: ";

    if (!(cin >> choice)) {
      cin.clear();
      while (cin.get() != '\n')
        ;
      cout << "Invalid input! Please enter a number.\n";
      continue;
    }

    if (choice == 1) {
      string id, val;
      cout << "Enter id: ";
      cin >> id;
      cout << "Enter value: ";
      cin >> val;
      objects.push_back(Factory::createSym(id, val));
      cout << "Success: SymString created.\n";
    }

    else if (choice == 2) {
      string id, val;
      cout << "Enter id: ";
      cin >> id;
      cout << "Enter decimal string: ";
      cin >> val;
      objects.push_back(Factory::createDec(id, val));
      cout << "Success: DecString created.\n";
    }

    else if (choice == 3) {
      if (objects.empty()) {
        cout << "Notice: List is empty!\n";
      } else {
        cout << "\nAll objects:\n";
        for (auto obj : objects)
          obj->Show();
      }
    }

    else if (choice == 4) {
      bool found = false;
      for (auto obj : objects) {
        DecString *d = dynamic_cast<DecString *>(obj);
        if (d) {
          d->ShowOct();
          found = true;
        }
      }
      if (!found)
        cout << "Notice: No decimal objects found to show in octal.\n";
    }

    else if (choice == 5) {
      if (objects.size() < 2) {
        cout << "Error: Need at least 2 objects to add them together!\n";
      } else {
        SymString *a = objects[objects.size() - 1]; // Last
        SymString *b = objects[objects.size() - 2]; // Second to last

        cout << "Adding last two objects:\n";

        DecString *da = dynamic_cast<DecString *>(a);
        DecString *db = dynamic_cast<DecString *>(b);

        if (da && db) {
          cout << "Type: Both are DecStrings (Numeric sum)\n";
          DecString result = (*da + *db);
          result.Show();
        } else {
          cout << "Type: Concatenation (at least one is a SymString)\n";
          SymString result = (*a + *b);
          result.Show();
        }
      }
    }

    else if (choice == 6) {
      if (objects.empty()) {
        cout << "Error: Nothing to delete!\n";
      } else {
        Factory::destroy(objects.back());
        objects.pop_back();
        cout << "Success: Last object deleted.\n";
      }
    }

  } while (choice != 0);

  for (auto obj : objects)
    delete obj;

  return 0;
}
