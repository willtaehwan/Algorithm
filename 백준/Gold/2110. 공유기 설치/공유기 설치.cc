#include<iostream>
#include<algorithm>
using namespace std;

int arr[200001];


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	
	int left = 1;
	int right = arr[N - 1] - arr[0];
	int ans = 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		int tmp = 0;
		int n = 1;
		for (int i = 1; i < N; i++) {
			tmp += arr[i] - arr[i-1];
			if (tmp >= mid) {
				n++;
				tmp = 0;
			}
		}

		if (n >= C) {
			ans = max(ans, mid);
			left = mid + 1;
		}
		else right = mid - 1;
	}

	cout << ans;

	return 0;
}