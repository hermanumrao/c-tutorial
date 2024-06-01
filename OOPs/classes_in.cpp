#include <iostream>
#include <string>

using namespace std;

class employee {
private:
  string Name;
  string company;
  int Age;

public:
  void intro() {
    cout << "name=" << Name << endl;
    cout << "company=" << company << endl;
  }

  employee(string name, string comp, int age) { // this is the constructor
    Name = name;
    company = comp;
    Age = age;
  }
};

int main(int argc, char *argv[]) {
  employee employee1("herman", "github", 20);
  // employee1.Name = "herman";         // enable if you have commented out the
  // constructor employee1.company = "github"; employee1.age = 20;
  //
  employee1.intro();

  return 0;
}
