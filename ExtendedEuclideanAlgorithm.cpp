#include <iostream>
#include <vector>

using namespace std;

//ax + by = gcd(a, b) を満たす整数x, yの組合わせを返す. 
//Extended Euclidean Algorithm
template<typename T>
pair<T, T> eea(T a, T b) {
	T x = 1, y = 0, p = 0, q = 1;
	while(b != 0){
		T s = a;
		a = b;
		T t = s/b;
		b = s%b;

		T i = x, j = y;
		x = p;
		y = q;
		p = t*p - i;
		q = t*q - j;
	}

	return pair<T, T>(x, y);
}

int main() {
	long long a, b;
	cin >> a >> b;
	pair<long long, long long> ans = eea(a, b);
	cout << ans.first << ", " << ans.second << "\n";
}
