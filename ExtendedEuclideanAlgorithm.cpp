#include <iostream>
#include <vector>

using namespace std;

//ax + by = gcd(a, b) を満たす整数x, yの組合わせを返す. Extended Euclidean Algorithm
//a = bq + r であるとき, b(qx+ y) + rx = gcd(a, b)であることを利用する.
template<typename T>
pair<T, T> eea(T a, T b) {
	int i = 1;

	//q, rの組を, r = 0になるまで求め続ける.
	//Ri = BQ(i+1) + R(i+1) 即ち, R(i+1) = R(i-1) % Ri, Q(i+1) = R(i-1) / Ri である.
	vector<pair<T, T>> qr;
	qr.push_back(pair<T, T>(0, b));
	qr.push_back(pair<T, T>(a / b, a % b));
	while (qr[i].second != 0) {
		qr.push_back(pair<T, T>(qr[i - 1].second / qr[i].second, qr[i - 1].second % qr[i].second));
		++i;
	}

	//Xi = Y(i+1)
	//Yi = X(i-1) - Q(i-1)*Xi
	//上記式を使ってX0, Y0を求める
	T x = 1;
	T y = 0;
	while (i > 0) {
		T t = y;
		T s = x - qr[i].first * y;
		x = t;
		y = s;
		--i;
	}

	return pair<T, T>(x, y);
}

int main() {
	long long a, b;
	cin >> a >> b;
	pair<T, T> ans = eea(a, b);
	cout << ans.first << ", " << ans.second << "\n";
}
