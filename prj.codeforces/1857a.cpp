#include <iostream>
int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        std::cin >> n;
        int sum = 0;
        for (int j = 0; j < n; j++) {
            int temp;
            std::cin >> temp;
            sum += temp;
        }
        if (sum % 2 == 0) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }
}