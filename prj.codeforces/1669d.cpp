#include <iostream>
#include <vector>
int main() {
	int t(0);
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n(0);
		std::cin >> n;
		std::string s;
		std::cin >> s;
		std::vector <std::string> lines;
		std::string temp;
		int count_b(0), count_r(0), flag(0);
		for (int j = 0; j < n; j++) {
			if (s[j] != 'W') {
				temp += s[j];
				if (s[j] == 'R') {
					count_r += 1;
				}
				else {
					count_b += 1;
				}
			}
			if ((s[j] == 'W' || j == n - 1) && temp != "") {
				if (count_b == 0 || count_r == 0) {
					flag = 1;
				}
				temp = "";
				count_b = 0;
				count_r = 0;
			}
		}
		if (flag == 1) {
			std::cout << "NO" << std::endl;
		}
		else {
			std::cout << "YES" << std::endl;
		}
	}
}