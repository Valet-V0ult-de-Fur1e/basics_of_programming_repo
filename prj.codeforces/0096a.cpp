#include <iostream>

int main() {
  int x;
  char l;
  bool f = false;
  std::string s;
  std::cin >> s;
  l = s[0];
  x = 1;
  for (int i = 1; i < s.length(); i++) {
    if (l == s[i]) {
      x++;
    }
    else if (x > 6) {
      break;
    }
    else {
      x = 1;
      l = s[i];
    }
  }
  if (x < 7) {
    std::cout << "NO";
  }
  else {
    std::cout << "YES";
  }
}