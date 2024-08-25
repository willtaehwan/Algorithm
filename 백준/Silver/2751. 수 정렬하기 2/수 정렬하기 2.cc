#include <iostream>

using namespace std;

int N;

bool DAT[2000001] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		DAT[a + 1000000] = 1;
	}

	for (int i = 0; i < 2000001; i++) {
		if (DAT[i]) cout << i - 1000000 << '\n';
	}

	return 0;
}