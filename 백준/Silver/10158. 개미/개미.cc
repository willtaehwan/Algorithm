#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int w, h, p, q, t;
	cin >> w >> h;
	cin >> p >> q;
	cin >> t;

	p += t;
	q += t;

	p %= w * 2;
	q %= h * 2;

	if (p > w) p = w * 2 - p;
	if (q > h) q = h * 2 - q;

	cout << p << " " << q;

	return 0;
}