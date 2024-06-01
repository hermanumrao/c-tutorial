#include <iostream>
#include <string>

using namespace std;

class employee {

private:
  string Name;
  string company;
  int Age;

public:
  int getage() { return Age; } // Now anyone can see value of age

  void setage(int age) { Age = age; } // Now anyone can change value of age

  string getname() { return Name; } // Now anyone and see value of name

  void intro() {
    cout << "name=" << Name << endl;
    cout << "company" << company << endl;
    cout << "Age" << Age << endl;
  }

  employee(string name, string comp, int age) {
    Name = name;
    company = comp;
    Age = age;
  }
};

int main(int argc, char *argv[]) {
  employee employee1("herman", "github", 20);
  // employee1.Name = "herman";
  // employee1.company = "github";
  // employee1.age = 20;
  //
  employee1.intro();
  employee1.setage(51);
  employee1.intro();

  return 0;
}
