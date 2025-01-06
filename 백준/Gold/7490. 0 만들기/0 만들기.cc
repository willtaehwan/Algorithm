#include <iostream>

using namespace std;

int N;
char temp[10];

void ans(int now, int res, int str, int flag) {

	if (now >= N) {
		res += (str * flag);
		if (res == 0) {
			for (int i = 1; i < N; i++) cout << i << temp[i - 1];
			cout << N << '\n';
		}
		return;
	}
	temp[now - 1] = ' ';
	ans(now + 1, res, str * 10 + now + 1, flag); // " "
	temp[now - 1] = '+';
	ans(now + 1, res + (str * flag), now + 1, 1);      // "+"
	temp[now - 1] = '-';
	ans(now + 1, res + (str * flag), now + 1, -1); // "-"
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		ans(1, 0, 1, 1);
		cout << '\n';
	}

	return 0;
}