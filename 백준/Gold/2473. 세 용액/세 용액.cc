#include <iostream>
#include <algorithm>
using namespace std;

int N;

long long arr[5010];
long long ans[3];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	long long min_result = 1e18;

	for (int i = 0; i < N - 2; i++) {

		int left = i + 1;
		int right = N - 1;

		while (left < right) {
			long long res = arr[i] + arr[left] + arr[right];

			if (min_result > abs(res)) {
				min_result = abs(res);
				ans[0] = arr[i];
				ans[1] = arr[left];
				ans[2] = arr[right];
			}

			if (res > 0) right--;
			if (res < 0) left++;
			if (res == 0) break;
		}


	}

	cout << ans[0] << " " << ans[1] << " " << ans[2];


	return 0;
}