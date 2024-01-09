#include <iostream>

int main() {
  int n_data = 0;
  std::cin >> n_data;
  std::string word;
  for (int i_data = 0; i_data < n_data; i_data++) {
    std::cin >> word;
    if (word.length() <= 10) {
      std::cout << word << '\n';
    }
    else {
      std::cout << word[0] << word.length() - 2 << word[word.length() - 1] << '\n';
    }
  }

  return 0;
}