#include <iostream>

using namespace std;

int N, M, K;

char map[101][101];
int nmap[101][101][81];

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

string word;
int cnt = 0;
int search_next(int row, int col, int idx) {
	
	if (idx == 0) {
		nmap[row][col][idx] = 1;
		return nmap[row][col][idx];
	}

	if (nmap[row][col][idx] != -1) return nmap[row][col][idx];

	int result = 0;
	char now_char = word[idx-1];
	for (int i = 0; i < 4; i++) {
		for (int k = 1; k <= K; k++) {
			int ner = row + dr[i] * k;
			int nec = col + dc[i] * k;
			if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;
			if (map[ner][nec] != now_char) continue;

			result += search_next(ner, nec, idx - 1);

		}
	}

	nmap[row][col][idx] = result;
	return nmap[row][col][idx];
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) map[i][j] = str[j];
	}

	cin >> word;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < word.size(); k++) {
				nmap[i][j][k] = -1;
			}
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == word[word.size()-1]) result += search_next(i, j, word.size()-1);
		}
	}
	cout << result;
	
	return 0;
}