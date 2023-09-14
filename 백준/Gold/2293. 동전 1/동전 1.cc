#include <iostream>

using namespace std;



int N, K;
int map[101] = { 0, };
int DP[10001] = { 0, };


int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
	DP[0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = map[i]; j <= K; j++) {
			DP[j] += DP[j - map[i]];
		}
	}

	cout << DP[K];

	return 0;
}