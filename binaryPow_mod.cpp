#include <iostream>
using namespace std;

template<typename T>
constexpr T binaryPow_mod(T radix, T index, T mod) noexcept {
	radix %= mod;
	T rtv = 1;
	while (index > 0) {
		if (index & 1) {
			rtv *= radix;
			rtv %= mod;
		}

		radix *= radix;
		radix %= mod;

		index = index >> 1;
	}

	return rtv;
}

template<typename T>
constexpr T invA_mod(T a, T mod) {
	return binaryPow_mod(a, mod - 2, mod);
}

int main() {
	unsigned long long radix, index, mod;
	cin >> radix >> index >> mod;

	cout << binaryPow_mod(radix, index, mod) << "\n";
}