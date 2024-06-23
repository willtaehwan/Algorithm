#include <iostream>

using namespace std;

int DP[2][31][1001] = { 0, };

int T, W;

int arr[1001] = { 0, };

int dp(int now, int w, int cnt) {
	if (cnt >= T || w < 0) return 0;

	if (DP[now][w][cnt]) return DP[now][w][cnt];
	
	DP[now][w][cnt] += max(dp(now, w, cnt + 1), dp((now + 1) % 2, w - 1, cnt + 1));
	
	if (arr[cnt] - 1 == now) DP[now][w][cnt]++;

	return max(DP[0][w][cnt], DP[1][w][cnt]);

}

int main() {

	cin >> T >> W;

	for (int i = 0; i < T; i++) cin >> arr[i];

	int result = max(dp(0, W, 0), dp(1, W - 1, 0));

	cout << result;

	return 0;
}