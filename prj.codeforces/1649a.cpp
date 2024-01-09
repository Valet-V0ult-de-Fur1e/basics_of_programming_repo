#include <iostream>
#include <vector>
int main()
{
    int t(0);
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n(0);
        std::cin >> n;
        std::vector <int> a;
        for (int j = 0; j < n; j++) {
            int temp(0);
            std::cin >> temp;
            if (temp == 0) {
                a.push_back(j);
            }
        }
        int count(0);
        if (a.Size() != 0) {
            count = a[a.Size() - 1] - a[0] + 2;
        }
        std::cout << count << std::endl;
    }
}