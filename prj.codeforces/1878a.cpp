#include <iostream>
#include <vector>

int main() {
	int t(0);
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n(0), k(0);
		std::cin >> n >> k;
		std::vector <int> a(n);
		for (int j = 0; j < n; j++) {
			std::cin >> a[j];
		}
		if (std::find(a.begin(), a.end(), k) != a.end()) {
			std::cout << "YES" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
	}
}