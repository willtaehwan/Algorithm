#include <iostream>

using namespace std;

int N;
int arr[202];
int len[202] = { 0, };

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) cin >> arr[i];

	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j >= 1; j--) {
			if (len[j] > len[i] && arr[j] < arr[i]) len[i] = len[j];
		}
		len[i]++;
		if (result < len[i]) result = len[i];
	}
	cout << N - result;

	return 0;
}