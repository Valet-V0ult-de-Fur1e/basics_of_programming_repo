#include <iostream>

int main() {
  std::string s;
  std::cin >> s;
  int c = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] < 'a') {
      c++;
    }
  }
  if (2 * c > s.length()) {
    for (int i = 0; i < s.length(); i++) {
      s[i] = toupper(s[i]);
    }
  }
  else {
    for (int i = 0; i < s.length(); i++) {
      s[i] = tolower(s[i]);
    }
  }
  std::cout << s;
}