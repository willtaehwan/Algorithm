#include <iostream>

using namespace std;

int coin[11] = { 0, };

int N, K;
int cnt = 0;

void coinCheck(int now, int V) {
	int next;
	if (V < 0 || now==0) {
		return;
	}

	if (coin[V] > now) {
		coinCheck(now, V - 1);
	}
	else {
		next = now - coin[V];
		cnt++;
		coinCheck(next, V);
	}


}

int main() {


	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	coinCheck(K,N-1);

	cout << cnt;

	return 0;
}