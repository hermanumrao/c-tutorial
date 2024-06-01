#include <iostream>
#include <string>

using namespace std;

class Abstract_employee { // abstract function
  virtual void AskForPromotion() = 0;
};

class employee : Abstract_employee {

private:
  string Name;
  int Age;

protected:
  string company;

public:
  int getage() { return Age; } // Now anyone can see value of age

  void setage(int age) { Age = age; } // Now anyone can change value of age

  string getname() { return Name; } // Now anyone and see value of name

  void intro() {
    cout << "name=" << Name << endl;
    cout << "company" << company << endl;
    cout << "Age" << Age << endl;
  }

  void AskForPromotion() {
    if (Age > 30)
      cout << "has been promoted";
    else
      cout << "not promoted";
  }

  employee(string name, string comp, int age) {
    Name = name;
    company = comp;
    Age = age;
  }
};

class developer
    : public employee { // using public keyword lets me use all the puble stuff
                        // of employee freely in the developer class
public:
  string fav_language;

  void show_lang() {
    cout << getname() << "uses " << fav_language << "and works in "
         << company; // name is private in employee class so i have to use
                     // getname method but company is protected so i can call it
                     // directly
  }

  developer(string name, string comp, string lang, int age)
      : employee(name, comp, age) {
    fav_language = lang;
  }
};

int main(int argc, char *argv[]) {
  employee employee1("herman", "github", 20);
  employee1.intro();
  employee1.AskForPromotion();
  employee1.setage(51);
  employee1.intro();
  employee1.AskForPromotion();

  developer d("herman", "github", "c++", 31);
  d.show_lang();
  d.intro();

  return 0;
}
