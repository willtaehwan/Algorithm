#include <iostream>

using namespace std;

int DP[1000002] = { 0, };

int main() {

	int N;
	cin >> N;
	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= N; i++) DP[i] = (DP[i - 1] + DP[i - 2]) % 15746;
	cout << DP[N];

	return 0;
}