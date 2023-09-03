#include <iostream>
using namespace std;

int map[1000001] = { 0, };

int main() {

	int N, num;

	cin >> N >> num;


	/*for (int i = 2; i <= num; i++) {
		map[i] = 1;
	}*/
	map[1] = 1;

	for (int i = 2; i < num; i++) {
		if (map[i] != 0) {
			continue;
		}
		for (int j = 2 * i; j <= num; j += i) {
			map[j] = 1;
		}
	}

	for (int i = N; i <= num; i++) {
		if (map[i] == 0) {
			printf("%d\n", i);
		}
	}


	return 0;
}