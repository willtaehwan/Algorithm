#include <iostream>

using namespace std;

int N;
int cnt = 0;
int result = 0;

void dfs(int now) {

	if (now == 0) {
		result++;
		return;
	}
	for (int i = 1; i <=3; i++) {
		int next = now - i;
		if (next < 0) continue;
		dfs(next);
	}
}

int main() {

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {

		result = 0;
		cnt = 0;
		cin >> N;
		dfs(N);

		cout <<result<<endl;
	}
	return 0;
}