#include <iostream>

using namespace std;

int N;

int arr[10002] = { 0, };
int DP[10002] = { 0, };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <=N; i++) cin >> arr[i];

	DP[1] = arr[1];
	DP[2] = arr[1] + arr[2];
	
	for (int i = 3; i <= N; i++) {
		int a = arr[i] + arr[i - 1] + DP[i - 3];
		int b = arr[i] + DP[i - 2];
		int c = DP[i - 1];
		DP[i] = max(a, max(b, c));
	}
	cout << DP[N];

	return 0;
}