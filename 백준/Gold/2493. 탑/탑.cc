#include <iostream>

using namespace std;

int N;
int h[500002] = { 0, };
int res[500002] = { 0, };

void res_check(int idx, int now) {

	if (h[idx] > h[now]) res[now] = idx;
	else res_check(res[idx], now);
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	h[0] = 1e9;
	for (int i = 1; i <= N; i++) {
		cin >> h[i];
		res_check(i - 1, i);
	}

	for (int i = 1; i <= N; i++) cout << res[i] << " ";

	return 0;
}