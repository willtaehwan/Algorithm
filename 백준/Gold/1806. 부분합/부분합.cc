#include <iostream>

using namespace std;

int N, S;

int arr[100001] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = 0;
	int minS = 2134567890;
	int sum = arr[0];
	int cnt = 1;
	while (left < N && right < N) {

		if (sum >= S) {
			sum -= arr[left];
			left++;

			if (minS > cnt) {
				minS = cnt;
			}
			cnt--;

			if (left > right) {
				cnt++;
				right++;
				sum += arr[right];
			}
		}
		else {
			cnt++;
			right++;
			sum += arr[right];
		}

		if (minS == 1) {
			break;
		}

	}

	if (minS == 2134567890) {
		cout << 0;
	}
	else {
		cout << minS;
	}
	

	return 0;
}