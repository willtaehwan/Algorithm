#include <iostream>

using namespace std;

int N;

void print_eq(int bit) {

	int temp[10] = { 0, };
	for (int i = N-2; i >= 0; i--) {
		int n = bit % 3;
		temp[i] = n;
		bit /= 3;
	}

	for (int i = 1; i < N; i++) {
		cout << i;
		if (temp[i - 1] == 0) cout << "+";
		else if (temp[i - 1] == 1) cout << "-";
		else cout << " ";
	}
	cout << N<<'\n';

}

void ans(int now, int res, int str, int flag, int bit) {

	if (now >= N) {
		res += (str * flag);
		if (res == 0) print_eq(bit);
		return;
	}
	ans(now + 1, res, str * 10 + now + 1, flag, bit * 3 + 2); // " "
	ans(now + 1, res + (str * flag), now + 1, 1, bit*3);      // "+"
	ans(now + 1, res + (str * flag), now + 1, -1, bit*3 + 1); // "-"
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;		
		ans(1, 0, 1, 1, 0);
		cout << '\n';
	}

	return 0;
}