#include <iostream>

int main() {
  int n_data = 0;
  std::cin >> n_data;
  int ans = 0;
  int a = 0;
  int b = 0;
  int c = 0;
  for (int i_data = 0; i_data < n_data; i_data++) {
    std::cin >> a >> b >> c;
    ans += (a + b + c > 1);
  }
  std::cout << ans;
  return 0;
}