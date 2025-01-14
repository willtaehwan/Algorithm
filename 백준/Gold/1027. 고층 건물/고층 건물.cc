#include <iostream>
#define ll long long
using namespace std;


int N;

int arr[51] = { 0, };
bool map[51][51] = { 0, };


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			map[i][j] = true;
			map[j][i] = true;
			if (i + 1 == j) continue;

			ll ax = j - i;
			ll ay = arr[j] - arr[i];
			for (int k = i + 1; k < j; k++) {
				ll bx = k - j;
				ll by = arr[k] - arr[j];
				ll result = ax * by - ay * bx;
				if (result >= 0) {
					map[i][j] = false;
					map[j][i] = false;
					break;
				}
			}
		}
	}
	int max_result = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) cnt += map[i][j];
		max_result = max(max_result, cnt);
	}
	cout << max_result;

	return 0;
}