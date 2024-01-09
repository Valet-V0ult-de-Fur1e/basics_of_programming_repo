#include <iostream>   
#include <vector>

int main() {
    int n(0), k(0), chel(0), count(0);
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (i == k - 1) {
            chel = a[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] >= chel && a[i] > 0) {
            count += 1;
        }
    }
    std::cout << count;
}