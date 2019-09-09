#include <iostream>
#include <utility>

typedef long long ll;

using namespace std;

ll gcd(ll m, ll n) {
	ll g = 1;

	while (m != 0) {
		if (m < n) swap(m, n);

		if (m & 1) {
			if (n & 1) {
				m = (m - n) >> 1;
			}
			else {
				n = n >> 1;
			}
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

ll lcm(ll m, ll n) {
	return (m * n) / gcd(m, n);
}

int main(){
    ll x, y;
    cin >> x >> y;
    cout << "gcd(" << x << y << ") = " << gcd(x, y) << "\n";
    cout << "lcm(" << x << y << ") = " << lcm(x, y) << "\n";

    return 0;
}