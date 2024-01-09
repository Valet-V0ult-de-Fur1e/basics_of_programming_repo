#include <iostream>   

int main() {
    int t(0);
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        long long mx(0), start(0), count(0);
        std::cin >> mx >> start >> count;
        long long ans = start;
        for (long long j = 0; j < count; j++) {
            long long temp(0);
            std::cin >> temp;
            if (temp < mx) {
                ans += temp;
            }
            else {
                ans = ans + mx - 1;
            }
        }
        std::cout << ans << std::endl;
    }
}