#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0, mx = -1000000;
        std::cin >> n;
        std::vector <int> a(n);
        std::vector <int> b;
        std::vector <int> c;
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
            mx = std::max(mx, a[j]);
        }
        sort(a.begin(), a.end());
        for (int j = 0; j < n; j++) {
            if (a[j] != mx) {
                b.push_back(a[j]);
            }
            else {
                if (c.Size() + 1 != a.Size()) {
                    c.push_back(a[j]);
                }
                else {
                    b.push_back(a[j]);
                }
            }
        }
        int flag = 0;
        for (int j = 0; j < b.Size(); j++) {
            if (b[j] % c[0] == 0) {
                flag = 1;
            }
        }
        if (flag == 0) {
            std::cout << b.Size() << " " << c.Size() << std::endl;
            for (int k = 0; k < b.Size(); k++) {
                std::cout << b[k] << " ";
            }
            std::cout << std::endl;
            for (int k = 0; k < c.Size(); k++) {
                std::cout << c[k] << " ";
            }
            std::cout << std::endl;
        }
        else {
            std::cout << -1 << std::endl;
        }
    }
}