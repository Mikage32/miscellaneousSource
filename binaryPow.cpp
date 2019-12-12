#include <iostream>
using namespace std;

template<typename T>
T binaryPow(T radix, T index) {
	T rtv = 1;
	while (index > 0) {
		if (index & 1) rtv *= radix;

		radix *= radix;
		index = index >> 1;
	}

	return rtv;
}

int main() {
	unsigned long long radix, index;
	cin >> radix >> index;

	cout << binaryPow(radix, index) << "\n";
}