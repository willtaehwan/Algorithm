#include <iostream>

using namespace std;

int arr[7] = { 0, };

int main() {

	for (int i = 0; i < 3; i++) {
		int a;
		cin >> a;
		arr[a]++;
	}
	int max_num = 0;
	int num;
	for (int i = 6; i >= 1; i--) {
		if (max_num < arr[i]) {
			num = i;
			max_num = arr[i];
		}
	}
	num *= 100;
	int result = 10;
	for (int i = 0; i < max_num; i++) {
		result *= 10;
		if (i == 2) num *= 10;
	}
	if (max_num == 1) result = 0;
	cout << result + num;
	return 0;
}