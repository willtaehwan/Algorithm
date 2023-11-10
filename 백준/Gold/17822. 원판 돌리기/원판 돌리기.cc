#include <iostream>
#include <queue>
using namespace std;

int N, M, T;

int map[52][51] = { 0, };
int visited[52][51] = { 0, };
struct Node {
	int row;
	int col;
};

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void bfs(int strow, int stcol) {

	queue<Node> q;
	q.push({ strow, stcol });
	visited[strow][stcol] = 1;
	int flag = 0;
	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];

			if (ner < 1 || ner >= N+1 ) continue;

			if (nec < 0) nec = M-1;
			else if (nec >= M) nec = 0;

			if (visited[ner][nec] != 0) continue;

			if (map[ner][nec] == map[now.row][now.col]) {
				flag = 1;
				visited[ner][nec] = 1;
				q.push({ ner,nec });

			}

		}

	}

	if (flag == 0) visited[strow][stcol] = 0;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int result = 0;

	for (int t = 0; t < T; t++) {
		//cout << "=======================" << endl;
		int x, d, k;
		cin >> x >> d >> k;
		
		for (int x1 = x; x1 <= N; x1 += x) {
			int temp[51] = { 0, };
			int re_k;
			if (d == 1) {
				re_k = k % M;
			}
			else {
				re_k = M - k % M;
			}
			
			for (int k1 = 0; k1 < re_k; k1++) {
				temp[k1] = map[x1][k1];
			}

			for (int k1 = re_k; k1 < M; k1++) {
				map[x1][k1 - re_k] = map[x1][k1];
			}

			for (int k1 = 0; k1 < re_k; k1++) {
				map[x1][M-re_k + k1] = temp[k1];
			}

		}

		/*for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/

		for (int i = 1; i <=N; i++) {
			for (int j = 0; j < M; j++) {
				
				if (map[i][j] == 0) continue;
				if (visited[i][j] == 1) continue;
				bfs(i, j);
				
			}
		}

		/*for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				cout << visited[i][j] << " ";
			}
			cout << endl;
		}*/

		int fflag = 0;

		for (int i = 1; i <=N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j] == 1) {
					fflag = 1;
					map[i][j] = 0;
				}
				visited[i][j] = 0;
			}
		}

		

		/*cout << endl;

		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}*/

		int sum = 0;
		float cnt = 0;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0) cnt++;
				sum += map[i][j];
			}
		}

		if (fflag == 0) {
			float ans = sum / cnt;
			int resum = 0;
			//cout << sum<<" "<<cnt<<" " << ans << endl;
			for (int i = 0; i <= N; i++) {
				for (int j = 0; j < M; j++) {
					if (map[i][j] == 0) continue;
					
					if (map[i][j] > ans) {
						map[i][j]--;
						resum += map[i][j];
					}
					else if (map[i][j] < ans) {
						map[i][j]++;
						resum += map[i][j];
					}
					else resum += map[i][j];
				}
			}
			sum = resum;
		}
		
		result = sum;
		//cout << result<<endl;
	}
	
	cout << result;

	return 0;
}