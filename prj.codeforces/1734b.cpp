#include <iostream>

int main() {
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		std::cin >> n;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < j + 1; k++) {
				if (k == 0 || k == j) {
					std::cout << 1 << " ";
				}
				else {
					std::cout << 0 << " ";
				}
			}
			std::cout << std::endl;
		}
	}
}