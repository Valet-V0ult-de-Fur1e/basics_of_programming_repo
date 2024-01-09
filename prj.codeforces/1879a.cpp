#include <iostream>
#include <vector>
int main() {
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n(0);
        std::cin >> n;
        std::vector<std::vector<int>> a(n, std::vector<int>(2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                std::cin >> a[i][j];
            }
        }
        int first_s = a[0][0], first_co = a[0][1], flag(0);
        for (int i = 1; i < n; i++) {
            if (a[i][0] >= first_s && a[i][1] >= first_co) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            std::cout << -1 << std::endl;
        }
        else {
            std::cout << first_s << std::endl;
        }
    }
}