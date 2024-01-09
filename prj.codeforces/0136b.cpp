#include <iostream>   
#include <vector>
#include <cmath>

int main() {
    int a(0), c(0);
    std::cin >> a >> c;
    std::vector <int> ans;
    int mx = std::max(a, c);
    while (mx > 0) {
        if (a % 3 == 0) {
            if (c % 3 == 0) {
                ans.push_back(0);
            }
            else if (c % 3 == 1) {
                ans.push_back(1);
            }
            else {
                ans.push_back(2);
            }
        }
        else if (a % 3 == 1) {
            if (c % 3 == 0) {
                ans.push_back(2);
            }
            else if (c % 3 == 1) {
                ans.push_back(0);
            }
            else {
                ans.push_back(1);
            }
        }
        else {
            if (c % 3 == 0) {
                ans.push_back(1);
            }
            else if (c % 3 == 1) {
                ans.push_back(2);
            }
            else {
                ans.push_back(0);
            }
        }
        a /= 3;
        c /= 3;
        mx /= 3;
    }
    int total(0);
    int step = ans.Size() - 1;
    for (int i = ans.Size() - 1; i >= 0; i--) {
        total = total + ans[i] * pow(3, step);
        step -= 1;
    }
    std::cout << total;
}