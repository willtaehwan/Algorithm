#include <iostream>

using namespace std;

int X, N;

int arr[250001];

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> X;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int result = 0;
	for (int i = 0; i < X; i++) result += arr[i];

	int max_result = result;
	int max_day = 1;
	for (int i = 0; i < N - X; i++) {
		result = result - arr[i] + arr[i + X];
		if (max_result < result) {
			max_result = result;
			max_day = 1;
		}
		else if (max_result == result) max_day++;
	}

	if (max_result == 0) {
		cout << "SAD";
		return 0;
	}

	cout << max_result<<'\n';
	cout << max_day;

	return 0;
}