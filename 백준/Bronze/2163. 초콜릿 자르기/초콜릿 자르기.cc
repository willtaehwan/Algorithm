#include <iostream>

using namespace std;

int arr[90001];

int ans(int now) {

	if (arr[now] != -1) return arr[now];

	int result = 0;
	if (now % 2 == 1) result = ans(now / 2) + ans(now / 2 + 1) + 1;
	else result = ans(now / 2) * 2 + 1;

	return result;
}

int main() {

	int N, M;

	cin >> N >> M;

	for (int i = 0; i <= N * M; i++)arr[i] = -1;
	arr[1] = 0;
	cout << ans(N*M);


	return 0;
}