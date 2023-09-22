#include <iostream>

using namespace std;

int arr[4000100] = { 0, };
int map[300010] = { 0, };

void makeMap() {
	int num = 4000100;
	for (int i = 2; i <= num; i++) {
		arr[i] = 1;
	}
	for (int i = 2; i < num; i++) {
		for (int j = i * 2; j < num; j += i) {
			arr[j] = 0;
		}
	}
	int cnt = 0;
	for (int i = 0; i < num; i++) {
		if (arr[i] == 1) {
			map[cnt] = i;
			cnt++;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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