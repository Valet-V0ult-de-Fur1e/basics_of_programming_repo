#include <iostream>
#include <vector>

int main() {
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        std::cin >> n;
        std::vector <int> a(n);
        int count = 0;
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
            if (a[j] == j + 1) {
                count += 1;
            }
        }
        if (count % 2 == 0) {
            std::cout << count / 2 << std::endl;
        }
        else {
            std::cout << count / 2 + 1 << std::endl;
        }
    }
}