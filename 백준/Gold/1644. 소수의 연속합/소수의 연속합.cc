#include <iostream>

using namespace std;

int map[300010] = { 0, };

int arr[4000001] = { 0, };

void makeMap() {	

	int num = 4000000;

	//cout << "dfsdfsdfs" << endl;

	arr[0] = arr[1] = 1;
	for (int i = 2; i < 2000; i++) {
		if (arr[i] == 0) {
			for (int j = i * 2; j <= 4000000; j += i) {
				arr[j] = 1;
			}
		}
	}
	//cout << "dsfsd" << endl;
	int cnt = 0;
	for (int i = 0; i <= num; i++) {
		if (arr[i] == 0) {
			map[cnt] = i;
			cnt++;
			//cout << i << endl;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//cout << "HI" << endl;
	makeMap();

	int N;
	cin >> N;

	int left = 0;
	int right = 0;
	int sum = map[0];
	int cnt = 0;
	while (map[left] <= N && map[right] <= N) {
		//cout << left<<"("<< map[left]<<")" << " " << right<<"("<< map[right] << ")  "<< sum << endl;
		if (sum < N) {
			right++;
			sum += map[right];
		}
		else {
			if (sum == N) {
				cnt++;
			}
			sum -= map[left];
			left++;
		}
		//cout << left << "(" << map[left] << ")" << " " << right << "(" << map[right] << ")  " << sum << endl;
	}

	cout << cnt;

	return 0;
}