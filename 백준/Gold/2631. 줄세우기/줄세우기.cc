#include <iostream>

using namespace std;

int N;
int arr[202];
int len[202];

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		len[i] = 1;
	}
	int result = 0;
	for (int i = 1; i <= N; i++) {
		bool flag = false;
		int max_length = 0;
		for (int j = i; j >= 1; j--) {
			if (len[j] > max_length && arr[j] < arr[i]) {
				flag = true;
				max_length = len[j];
			}
		}
		if(flag) len[i] = max_length + 1;
		if (result < len[i]) result = len[i];
	}

	cout << N - result;

	return 0;
}