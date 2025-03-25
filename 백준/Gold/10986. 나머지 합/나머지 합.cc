#include <iostream>
using namespace std;

int N, M;
int arr[1002] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	int sum = 0;
	arr[0] = 1;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		sum = (sum + a) % M;
		arr[sum]++;
	}
	long long ans = 0;
	for (int i = 0; i < M; i++) {
		long long n = arr[i];
		if (n == 0 || n == 1) continue;
		ans += (n * (n - 1)) / 2;
	}
	cout << ans;
	return 0;
}