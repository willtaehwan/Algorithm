#include <iostream>

using namespace std;

int N;

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int gcd1, gcd2;

		if (abs(x1) > abs(y1)) gcd1 = gcd(abs(x1), abs(y1));
		else gcd1 = gcd(abs(y1), abs(x1));

		if (abs(x2) > abs(y2)) gcd2 = gcd(abs(x2), abs(y2));
		else gcd2 = gcd(abs(y2), abs(x2));

		if (gcd1 == gcd2) cout << "1\n";
		else cout << "0\n";
	}


	return 0;
}