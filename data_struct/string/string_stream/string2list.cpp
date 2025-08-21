#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  std::string str_num = "12 3 123 2";
  std::vector<int> num_vect;

  std::stringstream ss(str_num);
  int num;
  while (ss >> num) {
    num_vect.push_back(num);
  }

  std::cout << "parsed numbers: ";
  for (int n : num_vect) {
    std::cout << n << ' ';
  }
  std::cout << std::endl;

  return 0;
}
