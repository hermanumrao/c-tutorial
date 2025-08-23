#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>

int answer(std::string s1, std::string s2) {
  int cnt = 0;

  return cnt;
}

int main(int argc, char *argv[]) {
  int cnt = 0;
  std::string s1;
  std::string s2;

  std::cin >> cnt;
  for (int i = 0; i < cnt; i++) {
    std::cin >> s1;
    std::cin >> s2;
    std::cout << answer(s1, s2) << std::endl;
  }

  return 0;
}
