#include <iostream>

int main() {
  std::string a;
  std::string b;
  std::cin >> a >> b;
  for (int i = 0; i < a.length(); i++) {
    if (std::tolower(a[i]) != std::tolower(b[i])) {
      std::cout << (std::tolower(a[i]) - std::tolower(b[i]) < 0 ? -1 : 1);
      return 0;
    }
  }
  std::cout << 0;
  return 0;
}