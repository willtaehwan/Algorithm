#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001];
int DP[1001];


int main() {

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	int result = 0;
	for (int i = 0; i < N; i++) {
		DP[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
		result = max(result, DP[i]);
	}
	cout << result;
	// for (int i = 0; i < N; i++) cout << DP[i]<<" ";
	

	return 0;
}