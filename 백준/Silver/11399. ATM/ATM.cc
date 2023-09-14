#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001] = { 0, };

int main() {

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	int sum = 0;
	int result = 0;
	for (int i = 0; i < N; i++) {
		result += arr[i];
		sum += result;
		
	}

	cout << sum;

	return 0;
}