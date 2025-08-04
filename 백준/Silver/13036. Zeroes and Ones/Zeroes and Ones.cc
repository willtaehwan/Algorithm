#include <iostream>

using namespace std;

/*

0110 -> 0000 -> 1100 -> 1111

0110 -> 1010 -> 1100 -> 1111

1111


*/
int T;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int N;
		cin >> N;

		string a, b;
		cin >> a >> b;
		a.push_back('0');
		int cnt = 0;
		bool flag = true;
		for (int i = 0; i < N; i++) {
			if (a[i] == b[i]) continue;
			if (a[i + 1] == '0') a[i + 1] = '1';
			else a[i + 1] = '0';
			cnt++;
			if (i == N - 1) flag = false;
		}
		if (flag) cout << cnt<<'\n';
		else cout << -1<<'\n';
	}


	return 0;
}