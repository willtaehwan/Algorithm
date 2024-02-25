#include <iostream>

using namespace std;

int N;
int F[32] = { 0, };

int dp(int now) {

	if (now % 2 == 1) return 0;
	if (F[now - 2] == 0) dp(now - 2);
	int answer = F[now-2] * F[2];
	for (int i = 0; i<now-2; i += 2) answer += F[i] * 2;
	F[now] = answer;

	return F[now];
}

int main() {

	cin >> N;
	F[0] = 1; F[1] = 0; F[2] = 3;

	// F[N] = F[N-2]*F[2] + F[N-4]*2 + ... + F[2]*2 + F[0]*2
	int result = dp(N);

	cout << result;

	return 0;
}