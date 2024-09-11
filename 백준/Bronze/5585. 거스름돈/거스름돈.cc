#include <iostream>

using namespace std;

int arr[] = { 500,100,50,10,5,1 };
int N;
int main() {

	cin >> N;
	int now = 1000 - N;
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		while (now >= arr[i]) {
			now -= arr[i];
			cnt++;
		}
		if (now == 0) break;
	}
	cout << cnt;

	return 0;
}