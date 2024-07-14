#include <iostream>
#define ll long long
using namespace std;

int P, M, num;

ll ans(ll m) {

	int prev = 0;
	int cur = 1;
	int temp = 0;

	for (ll i = 0; i < m * m; i++) {
		temp = (cur + prev) % m;
		prev = cur;
		cur = temp;

		if (cur == 1 && prev == 0) {
			return i + 1;
		}
	}

}

int main() {

	cin >> P;

	for (int i = 0; i < P; i++) {
		cin >> num >> M;
		cout << num << " " << ans(M)<<'\n';
	}

	return 0;
}