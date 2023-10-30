#include <iostream>
#include <vector>
using namespace std;

int N, M;
int map[51][51] = { 0, };
int dist[15][101] = { 0, };

int visited[15] = { 0, };
int path[15] = { 0, };

int cnt = 0;
int finResult = 9999;
struct Node {
	int row;
	int col;
};

vector<Node> ch;
vector<Node> home;

void dfs(int now, int prev) {

	if (now >= M) {

		/*for (int i = 0; i < cnt; i++) {
			cout << path[i] << " ";
		}*/
		//cout << endl;
		int sumResult = 0;
		for (int i = 0; i < home.size(); i++) {
			int minScore = 999;
			for (int j = 0; j < cnt; j++) {
				if (minScore > dist[path[j]][i]) {
					minScore = dist[path[j]][i];
				}
			}
			//cout << minScore << " ";
			sumResult += minScore;
		}
		//cout << "  / Sum Result = " << sumResult << endl;

		if (finResult > sumResult) {
			finResult = sumResult;
		}

		return;
	}

	for (int i = 0; i < ch.size(); i++) {
		if (prev >= i) continue;
		if (visited[i] != 0) continue;

		visited[i] = 1;
		path[cnt++] = i;
		dfs(now + 1, i);
		path[cnt--] = 0;
		visited[i] = 0;

	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				ch.push_back({ i,j });
			}
			else if (map[i][j] == 1) {
				home.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < ch.size(); i++) {
		for (int j = 0; j < home.size(); j++) {
			dist[i][j] = abs(ch[i].row - home[j].row) + abs(ch[i].col - home[j].col);
			//cout << dist[i][j]<<" ";
		}
		//cout << endl;
	}

	
	dfs(0,-1);

	cout << finResult;

	return 0;
}