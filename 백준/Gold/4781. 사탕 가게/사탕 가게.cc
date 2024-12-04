#include <iostream>

using namespace std;

int N, M;

struct Node {
	int c;
	int p;
};

Node cd[5002];
int DP[10001] = { 0, };

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		double tempM;
		cin >> N >> tempM;
		M = (int)(tempM * 100 + 0.5);

		if (N == 0) break;

		for (int i = 0; i < N; i++) {
			int c;
			double p;
			cin >> c >> p;
			int cost = (int)(p * 100 + 0.5);
			cd[i] = { c,cost };
		}

		for (int i = 0; i <= M; i++) DP[i] = 0;

		for (int i = 0; i < N; i++) {
			for (int j = cd[i].p; j <= M; j++) {
				DP[j] = max(DP[j], DP[j - cd[i].p] + cd[i].c);
			}
		}
		cout << DP[M] << '\n';
	}

	return 0;
}