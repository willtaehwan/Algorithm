#include <iostream>

using namespace std;

int N;
int ans = 0;
int col[16] = { 0, };

void dfs(int row) {

	if (row == N) {
		ans++;
		return;
	}

	for (int c = 0; c < N; c++) {
		bool flag = true;
		for (int pr = 0; pr < row; pr++) {
			int pc = col[pr];
			if (pc == c) flag = false;
			if (pc - pr == c - row) flag = false;
			if (pc + pr == c + row) flag = false;
		}
		if (flag) col[row] = c;
		else continue;

		dfs(row + 1);

	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	dfs(0);

	cout << ans;

	return 0;
}