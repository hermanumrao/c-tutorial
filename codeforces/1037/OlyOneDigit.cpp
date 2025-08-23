#include <algorithm>
#include <iostream>
#include <ostream>

int smallest_digit(int x) {
  int y = x % 10;
  x /= 10;
  while (x > 0) {
    y = std::min(y, x % 10);
    x /= 10;
  }
  return y;
}

int main(int argc, char *argv[]) {
  int cnt = 0;
  int a = 0;

  std::cin >> cnt;
  for (int i = 0; i < cnt; i++) {
    std::cin >> a;
    std::cout << smallest_digit(a) << std::endl;
  }

  return 0;
}
