#include <iostream>

using namespace std;

int N, M;

bool map[1002][1002] = { 0, };

int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) cin >> map[i][0];
	for (int i = 1; i <= M; i++) cin >> map[0][i];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i - 1][j] != map[i][j - 1]) map[i][j] = 1;
		}
	}

	cout << map[N][M];


	return 0;
}