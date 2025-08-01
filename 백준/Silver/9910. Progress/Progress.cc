#include <iostream>

using namespace std;

int inp[501] = { 0, };
bool arr[100001] = { 0, };

int N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> inp[i];
		arr[inp[i]] = true;
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			int a = inp[i];
			int m = inp[j] - a;
			int cnt = 2;
			while (arr[a+m*cnt]) cnt++;
			ans = max(ans, cnt);
		}
	}

	cout << ans;
	

	return 0;
}