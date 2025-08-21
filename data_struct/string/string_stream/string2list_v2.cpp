#include <complex>
#include <iostream>
#include <iterator>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  std::string num_str = "1,2,3,445,54";
  std::vector<int> num_vec;

  std::stringstream ss(num_str);
  int n;
  std::string token;

  while (std::getline(ss, token, ',')) {
    try {
      num_vec.push_back(std::stoi(token));
    } catch (const std::invalid_argument &e) {
      std::cerr << "invalid number format: " << token << std::endl;
    } catch (const std::out_of_range &e) {
      std::cerr << "number out of range" << token << std::endl;
    }
  }

  std::cout << "parsed numbers: ";
  for (int num : num_vec) {
    std::cout << num << ' ';
  }
  std::cout << std::endl;

  return 0;
}
