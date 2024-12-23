#include <iostream>

using namespace std;

int DP[3] = { 0, };

int main() {

	int N;
	cin >> N;
	DP[0] = 1;
	DP[1] = 2;
	
	int cnt = 2;
	while (cnt < N) {
		int result = 0;
		for (int i = 0; i < 3; i++) {
			if (cnt % 3 != i) result += DP[i];
		}
		DP[cnt%3] = result % 15746;
		cnt++;
	}
	cout << DP[(N-1)%3];

	return 0;
}