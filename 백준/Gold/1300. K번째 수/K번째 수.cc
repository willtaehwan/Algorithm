#include <iostream>

using namespace std;

int N, K;

int cal_res(int m) {

	int res = 0;
	for (int i = 1; i <= N; i++) {
		int now = min(m / i, N);
		res += now;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;

	int l = 1;
	int r = 1e9;
	int ans = 0;
	while (l < r) {
		int mid = (l + r) / 2;

		int res = cal_res(mid);
		// cout << l << " " << r << " " << res << '\n';
		if (K <= res) {
			ans = mid;
			r = mid;
		}
		if (K > res) l = mid + 1;

	}

	cout << ans;

	return 0;
}