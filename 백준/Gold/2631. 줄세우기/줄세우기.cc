#include <iostream>

using namespace std;

int N;
int arr[202];
int parent[202];

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		parent[i] = 1;
	}
	int result = 0;
	for (int i = 1; i <= N; i++) {
		bool flag = false;
		int max_length = 0;
		for (int j = i; j >= 1; j--) {
			if (parent[j] > max_length && arr[j] < arr[i]) {
				flag = true;
				max_length = parent[j];
			}
		}
		if(flag) parent[i] = max_length + 1;
		if (result < parent[i]) result = parent[i];
	}

	cout << N - result;

	return 0;
}