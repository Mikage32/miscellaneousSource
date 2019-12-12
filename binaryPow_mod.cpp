#include <iostream>
using namespace std;

template<typename T>
T binaryPow_mod(T radix, T index, T mod) {
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

int main() {
	unsigned long long radix, index, mod;
	cin >> radix >> index >> mod;

	cout << binaryPow_mod(radix, index, mod) << "\n";
}