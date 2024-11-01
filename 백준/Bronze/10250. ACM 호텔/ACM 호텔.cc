#include<iostream>

using namespace std;

int main() {

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int h, w, n;
		cin >> h >> w >> n;

		int row = n % h;
		int ho = n / h + 1;

		if (row == 0) {
			cout << h;
			ho -= 1;
		}
		else cout << n % h;

		if (ho < 10)cout << 0 << ho;
		else cout << ho;
		cout << '\n';
	}

	return 0;
}