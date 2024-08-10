#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
	int sum;
	int re;
};

int N;

long long arr[100010];

int min_result = 2e9 + 1;

Node searchN(int n) {

	int left = n + 1;
	int right = N - 1;
	int mid = 0;
	int res = 0;

	int min_r = 2e9 + 1;
	int min_m = 0;

	while (left <= right) {
		
		mid = (left + right) / 2;
		res = arr[mid] + arr[n];
		//cout << n << "  / " << left << ", " << right <<"  mid = " << mid << " result : " << res << '\n';
		if (min_r > abs(res)) {
			min_r = abs(res);
			min_m = mid;
		}
		if (left == right) break;
		if (res > 0) right = mid;
		if (res < 0) left = mid+1;
		if (res == 0) break;

	}


	return { min_r, min_m };
}


int main() {

	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];

	int ans1 = -1;
	int ans2 = -1;

	for (int i = 0; i < N - 1; i++) {
		Node result = searchN(i);
		if (min_result > result.sum) {
			//cout <<"          " << i << " , " << result.re<<"  res = "<<result.sum << '\n';
			min_result = result.sum;
			ans1 = arr[i];
			ans2 = arr[result.re];
		}
		if (min_result == 0) break;
	}

	cout << ans1 << " " << ans2;

	return 0;
}