#include <iostream>
#include <vector>

typedef long long ll;
typedef std::pair<long long, long long> pll;

using namespace std;

//ax + by = gcd(a, b) を満たすx, yの組合わせを返す
pll eea(ll a, ll b) {
	int i = 1;
	vector<pll> qr;
	qr.push_back(pll(0, b));
	qr.push_back(pll(a / b, a % b));
	while (qr[i].second != 0) {
		qr.push_back(pll(qr[i - 1].second / qr[i].second, qr[i - 1].second % qr[i].second));
		++i;
	}

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
