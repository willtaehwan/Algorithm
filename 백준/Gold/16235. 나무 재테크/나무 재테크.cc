#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int left, int right) {
	if (left > right) return true;
	else return false;
}

int N, M, K;

vector<int> Tree2[11][11];

int map[11][11] = { 0, };
int New[11][11] = { 0, };

int initmap[11][11] = { 0, };

int dr[] = { -1,-1,-1,0,0,1,1,1 };
int dc[] = { -1,0,1,-1,1,-1,0,1 };



void WSS() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (Tree2[i][j].size() == 0) continue;

			sort(Tree2[i][j].begin(), Tree2[i][j].end(),cmp);

			int a = Tree2[i][j].size();
			
			int flag = 0;
			vector<int> temp;
			for (int k = a - 1; k >= 0; k--) {
				int now = Tree2[i][j][k];
				
				Tree2[i][j].pop_back();
				if (map[i][j] >= now && flag == 0) {
					map[i][j] -= now;
					temp.push_back(now + 1);
					if ((now + 1) % 5 == 0) {
						New[i][j]++;
					}
				}
				else {
					flag = 1;
					map[i][j] += (now / 2);
				}
				
			}
			
			for (int k = 0; k < temp.size(); k++) {
				Tree2[i][j].push_back(temp[k]);
			}
		}
	}

	return;
}



void FW() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] += initmap[i][j];
			if (New[i][j] == 0) continue;

			for (int k = 0; k < 8; k++) {
				int ner = i + dr[k];
				int nec = j + dc[k];

				if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;
				for (int NewTree = 0; NewTree < New[i][j]; NewTree++) {
					Tree2[ner][nec].push_back(1);
				}

			}

			New[i][j] = 0;
		}
	}


	return;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> initmap[i][j];
			map[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int r, c, year;
		cin >> r >> c >> year;
		Tree2[r - 1][c - 1].push_back(year);
	}


	for (int i = 0; i < K; i++) {
		WSS();
		FW();
	}

	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += Tree2[i][j].size();
		}
	}

	cout << sum;
	return 0;
}