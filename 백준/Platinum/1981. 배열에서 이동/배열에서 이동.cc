#include <iostream>

using namespace std;

int N;

int map[105][105] = { 0, };
bool visited[105][105] = { 0, };

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };


bool dfs(int row, int col, int min, int max) {

	if (map[row][col] < min || map[row][col] > max) return false;
	if (row == N - 1 && col == N - 1) return true;
	visited[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int ner = row + dr[i];
		int nec = col + dc[i];
		if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;
		if (visited[ner][nec]) continue;

		if (dfs(ner, nec, min, max)) return true;

	}

	return false;
}

bool dec(int gap) {

	for (int g = 0; g <= 200 - gap; g++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visited[i][j] = false;
			}
		}

		if (dfs(0, 0, g, g + gap)) return true;
		
	}

	return false;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int high = 200;
	int low = -1;
	while(low + 1 < high){
		int mid = (high + low)/2;

		if(dec(mid)) high = mid;
		else low = mid;
	}

	cout << high;

	return 0;
}