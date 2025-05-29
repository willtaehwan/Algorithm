#include <iostream>

using namespace std;

int N;

int arr[1001] = { 0, };
int rDP[1001] = { 0, };
int lDP[1001] = { 0, };

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N; i++) {
		rDP[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) rDP[i] = max(rDP[i], rDP[j] + 1);
		}
	}

	int ans = 0;

	for (int i = N-1; i >= 0; i--) {
		lDP[i] = 1;
		for (int j = N-1; j > i; j--) {
			if (arr[i] > arr[j]) lDP[i] = max(lDP[i], lDP[j] + 1);
		}
		ans = max(ans, rDP[i] + lDP[i]);
	}

	cout << ans - 1;

	return 0;
}