#include <iostream>

int main() {
	int t(0);
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n(0);
		std::cin >> n;
		int sum(0);
		for (int j = 0; j < n - 1; j++) {
			int temp(0);
			std::cin >> temp;
			sum += temp;
		}
		std::cout << -sum << std::endl;
	}
}