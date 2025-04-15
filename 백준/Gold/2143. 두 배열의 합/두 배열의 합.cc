#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M;

int A[1002] = { 0, };
int B[1002] = { 0, };

vector<int> sA;
vector<int> sB;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		A[i] = A[i - 1] + a;
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		int b;
		cin >> b;
		B[i] = B[i - 1] + b;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			sA.push_back(A[i] - A[j]);
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < i; j++) {
			sB.push_back(B[i] - B[j]);
		}
	}

	sort(sA.begin(), sA.end());
	sort(sB.begin(), sB.end());
	
	long long ans = 0;
	int na = sA.size() - 1;
	int nb = 0;
	long long cnt = 1;
	while (1) {

		if (na < 0 || nb >= sB.size()) break;

		if (sA[na] + sB[nb] > T) {
			na--;
			cnt = 1;
		}
		else if (sA[na] + sB[nb] < T) {
			nb++;
			cnt = 1;
		}
		else if (na > 0 && sA[na] == sA[na - 1]) {
			cnt++;
			na--;
		}
		else {
			ans += cnt;
			nb++;
		}
	}

	cout << ans;

	return 0;
}