#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int A[100001] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}


	sort(A+1, A + N);
	/*cout << endl;
	for (int i = 1; i <= N; i++) {
		cout << A[i] << " ";
	}
	cout << endl;*/
	int left = 1;
	int right = 2;
	int minM = 2134567890;
	while (right <= N && left <= N) {
		int result = A[right] - A[left];
		if (result >= M) {
			if (minM > result) {
				minM = result;
			}
			left++;
		}
		else {
			right++;
		}

		if (minM == M) {
			break;
		}
	}
	
	cout << minM;

	return 0;
}