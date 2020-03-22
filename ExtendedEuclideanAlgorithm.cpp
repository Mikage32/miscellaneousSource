#include <iostream>
#include <vector>

//ax + by = gcd(a, b) を満たす整数x, yの組合わせを返す. 
//Extended Euclidean Algorithm
template<typename T>
constexpr std::pair<T, T> eea(T a, T b) noexcept {
	T x = 1, y = 0, p = 0, q = 1;
	while (b != 0) {
		T s = a;
		a = b;
		T t = s / b;
		b = s % b;

		T i = x, j = y;
		x = p;
		y = q;
		p = i - t * p;
		q = j - t * q;
	}

	return pair<T, T>(x, y);
}

template<typename T>
constexpr T inv(T a, T mod) noexcept{
	T invA = eea(a, mod).first;
	if(invA < 0) invA += mod;

	return invA;
}

int main() {
	long long a, b;
	std::cin >> a >> b;
	std::pair<long long, long long> ans = eea(a, b);
	std::cout << ans.first << ", " << ans.second << "\n";
}
