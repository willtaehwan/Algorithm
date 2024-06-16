#include <iostream>
#include <vector>

using namespace std;

int P;

int arr[20];

int main() {

	cin >> P;

	for (int tc = 1; tc <= P; tc++) {
		int tc_num;
		cin >> tc_num;
		
		int cnt = 0;

		for (int i = 0; i < 20; i++) {
			cin >> arr[i];
		}

		for (int i = 1; i < 20; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[i] < arr[j]) cnt++;
			}
		}

		cout << tc << " " << cnt << '\n';
	}

	return 0;
}