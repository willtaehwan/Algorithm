#include <iostream>

using namespace std;

int A[10001] = { 0, };

int main() {

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int cnt = 0;
	int left = 0;
	int right = 0;
	int sum = A[0];
	while (right <N && left <N) {
		//cout << " sum is = " << sum <<" "<<left<<" "<<right<< endl;
		if (sum < M) {
			right++;
			sum += A[right];
		}
		else if (sum > M) {
			sum -= A[left];
			left++;
		}
		else {
			cnt++;
			right++;
			sum += A[right];
		}
	}

	cout << cnt;


	return 0;
}