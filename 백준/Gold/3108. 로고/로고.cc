#include <iostream>

using namespace std;

int N;

int map[1002][4] = { 0, };
int Par[1002];

bool check(int a, int b) {

	if (map[a][0] > map[b][2] || map[a][2] < map[b][0] || map[a][1] > map[b][3] || map[a][3] < map[b][1]) return false;
	if (map[a][2] > map[b][2] && map[a][0] < map[b][0] && map[a][1] < map[b][1] && map[a][3] > map[b][3]) return false;
	if (map[b][2] > map[a][2] && map[b][0] < map[a][0] && map[b][1] < map[a][1] && map[b][3] > map[a][3]) return false;
	return true;
}

int Find(int A) {
	if (Par[A] == A) return A;
	return Find(Par[A]);
}

void Union(int a, int b) {
	//cout << a << " , " << b << "\n";
	int rootA = Find(a);
	int rootB = Find(b);
	if (rootA == rootB) return;
	Par[rootA] = rootB;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <=N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> map[i][j];
		}
		Par[i] = i;
	}

	Par[N+1] = N+1;

	for (int i = 1; i <= N+1; i++) {
		for (int j = i + 1; j <= N+1; j++) {
			if (check(i, j)) Union(i, j);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N+1; i++) {
		if (Par[i] == i) cnt++;
	}

	cout << cnt - 1;

	return 0;
}