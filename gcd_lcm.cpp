#include <iostream>
#include <utility>

template<typename T>
constexpr T gcd(T m, T n) noexcept {
	T g = 1;

	while (m != 0) {
		if (m < n) swap(m, n);
		
		if (m & 1) {
			if (n & 1) m = (m - n) >> 1;
			else n = n >> 1;
		}
		else {
			if (n & 1) {
				m = m >> 1;
			}
			else {
				n = n >> 1;
				m = m >> 1;
				g = g << 1;
			}
		}
	}

	return g * n;
}

template<typename T>
constexpr T lcm(T m, T n) noexcept {
	return (m * n) / gcd(m, n);
}

int main(){
    long long x, y;
    std::cin >> x >> y;
    std::cout << "gcd(" << x << y << ") = " << gcd(x, y) << "\n";
    std::cout << "lcm(" << x << y << ") = " << lcm(x, y) << "\n";

    return 0;
}