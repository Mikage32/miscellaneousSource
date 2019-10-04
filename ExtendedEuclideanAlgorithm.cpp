#include <iostream>
#include <vector>

typedef long long ll;
typedef std::pair<long long, long long> pll;

using namespace std;

//ax + by = gcd(a, b) を満たすx, yの組合わせを返す. Extended Euclidean Algorithm
//a = bq + r であるとき, b(qx+ y) + rx = gcd(a, b)であることを利用する.
pll eea(ll a, ll b) {
	int i = 1;

	//q, rの組を, r = 0になるまで求め続ける.
	//Ri = BQ(i+1) + R(i+1) 即ち, R(i+1) = R(i-1) % Ri, Q(i+1) = R(i-1) / Ri である.
	vector<pll> qr;
	qr.push_back(pll(0, b));
	qr.push_back(pll(a / b, a % b));
	while (qr[i].second != 0) {
		qr.push_back(pll(qr[i - 1].second / qr[i].second, qr[i - 1].second % qr[i].second));
		++i;
	}

	//Xi = Y(i+1)
	//Yi = X(i-1) - Q(i-1)*Xi
	//上記式を使ってX0, Y0を求める
	ll x = 1;
	ll y = 0;
	while (i > 0) {
		ll t = y;
		ll s = x - qr[i].first * y;
		x = t;
		y = s;
		--i;
	}

	return pll(x, y);
}

int main() {
	int a, b;
	cin >> a >> b;
	pll ans = eea(a, b);
	cout << ans.first << ", " << ans.second << "\n";
}
