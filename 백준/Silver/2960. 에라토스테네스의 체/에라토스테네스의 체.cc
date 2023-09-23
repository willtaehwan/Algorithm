#include <iostream>

using namespace std;

int N,K;

int arr[1001] = { 0, };

int main() {

	cin >> N >> K;

	arr[0] = arr[1] = 1;
	int cnt = 0;
	int flag = 0;
	for (int i = 2; i <= N; i++) {
		if (flag == 1) break;
		for (int j = i; j <= N; j+=i) {

			if (arr[j] == 1) continue;

			cnt++;
			
			if (cnt == K) {
				flag = 1;
				cout << j;
				break;
			}
			arr[j] = 1;
			

		}
	}

	return 0;
}