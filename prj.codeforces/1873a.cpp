#include <iostream>
#include <string>
int main() {
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::string s;
        std::cin >> s;
        if (s[0] == 'a' || s[1] == 'b' || s[2] == 'c') {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }
}