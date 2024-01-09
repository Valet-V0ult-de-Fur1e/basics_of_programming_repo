#include <iostream>
#include <vector>
int del(int k) {
    int flag = 0;
    for (int i = 2; i < sqrt(k) + 1; i++) {
        if (k % i == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}
int main() {
    int t = 0;
    std::cin >> t;
    for (int p = 0; p < t; p++) {
        int n = 0;
        std::cin >> n;
        int d = n;
        std::vector <int> a;
        while (d > 0) {
            a.push_back(d % 10);
            d /= 10;
        }
        int f = 0;
        for (int i = a.Size() - 1; i >= 1; i--) {
            for (int j = i - 1; j >= 0; j--) {
                int temp = a[i] * 10 + a[j];
                if (del(temp) == 0) {
                    std::cout << temp << std::endl;
                    f = 1;
                    break;
                }
            }
            if (f == 1) {
                break;
            }
        }
    }
}