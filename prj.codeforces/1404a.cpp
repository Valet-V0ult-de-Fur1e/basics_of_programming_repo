#include <iostream>
#include <string>

int main() {
	int t(0);
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n(0), k(0);
		std::string s;
		std::cin >> n >> k;
		std::cin >> s;
		int flag(0);
		for (int j = 0; j < n - k; j++) {
			if (s[j] != '?') {
				if (s[j + k] == '?' || s[j + k] == s[j]) {
					s[j + k] = s[j];
				}
				else {
					flag = 1;
				}
			}
			else {
				if (s[j + k] != '?') {
					s[j] = s[j + k];
				}
			}
		}
		for (int j = n - 1; j >= k; j--) {
			if (s[j] != '?') {
				if (s[j - k] == '?' || s[j - k] == s[j]) {
					s[j - k] = s[j];
				}
				else {
					flag = 1;
				}
			}
			else {
				if (s[j - k] != '?') {
					s[j] = s[j - k];
				}
			}
		}
		if (flag != 1) {
			int count_zero(0), count_ones(0);
			for (int j = 0; j < k; j++) {
				if (s[j] == '0') {
					count_zero += 1;
				}
				else if (s[j] == '1') {
					count_ones += 1;
				}
				if (count_zero > k / 2 || count_ones > k / 2) {
					flag = 1;
					break;
				}
			}
		}
		if (flag != 1) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
}