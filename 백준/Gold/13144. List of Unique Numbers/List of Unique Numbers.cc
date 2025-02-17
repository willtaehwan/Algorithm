#include <iostream>

using namespace std;

int N;
int arr[100002] = { 0, }; // 입력 값
int idx[100002] = { 0, }; // 숫자가 존재하는 위치

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	long long tot = 0;
	int left = 1;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];

		if (idx[arr[i]] == 0) idx[arr[i]] = i;
		else {
			int temp = idx[arr[i]];
			for (int j = left; j <= temp; j++) {
				tot += i - idx[arr[j]];
				idx[arr[j]] = 0;
			}
			left = temp + 1;
			idx[arr[i]] = i;
		}
	}

	for (int i = 1; i <= 100000; i++) {
		if (idx[i] != 0) tot += N - idx[i] + 1;
	}
	cout << tot;

	return 0;
}