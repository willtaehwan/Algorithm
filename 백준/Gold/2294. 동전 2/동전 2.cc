#include <iostream>
using namespace std;

int N, K;

int coin[101] = { 0, };
int DP[10001] = { 0, };
int func(int now) {

	if (now >= K) {
		return 0;
	}

	if (DP[now] != 0) {
		return DP[now];
	}

	int bestC = 21345678;
	for (int i = 0; i < N; i++) {
		int next = now + coin[i];

		if (next > K) continue;

		int nextScore = func(next);

		bestC = min(bestC, nextScore);

	}

	int nowScore = bestC + 1;
	DP[now] = nowScore;
	return nowScore;

}

int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	func(0);

	if (DP[0] > 11000) {
		cout << -1;
	}
	else {
		cout << DP[0];
	}
	

	return 0;
}