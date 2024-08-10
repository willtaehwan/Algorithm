#include <iostream>

using namespace std;

int N;

int arr[100010];

int min_result = 2e9 + 1;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];
	
	int left = 0;
	int right = N - 1;

	int ans1, ans2;

	while (right != left) {
		int res = arr[left] + arr[right];
		if (min_result > abs(res)) {
			min_result = abs(res);
			ans1 = arr[left];
			ans2 = arr[right];
		}

		if (min_result == 0) break;
		if (res > 0) right--;
		if (res < 0) left++;
	}

	cout << ans1 << " " << ans2;

	return 0;
}