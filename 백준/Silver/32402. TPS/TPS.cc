#include <iostream>

using namespace std;

int N;
int dr[] = { 1,0,-1,0 };
int dc[] = { 0,1,0,-1 };

int mr[4][4] = {
	{-1,0,1,0},
	{0,-1,0,1},
	{1,0,-1,0},
	{0,1,0,-1}
};

int mc[4][4] = {
	{0,1,0,-1},
	{-1,0,1,0},
	{0,-1,0,1},
	{1,0,-1,0}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	int dir = 2;
	int row = 0;
	int col = 0;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		
		if (s == "MR") dir = (dir + 5) % 4;
		else if (s == "ML") dir = (dir + 3) % 4;
		else if (s == "W") {
			row = row + mr[dir][0];
			col = col + mc[dir][0];
		}
		else if (s == "A") {
			row = row + mr[dir][1];
			col = col + mc[dir][1];
		}
		else if (s == "S") {
			row = row + mr[dir][2];
			col = col + mc[dir][2];
		}
		else if (s == "D") {
			row = row + mr[dir][3];
			col = col + mc[dir][3];
		}
		
		int cr = row + dr[dir];
		int cc = col + dc[dir];

		cout << col << " " << row << " " << cc << " " << cr << '\n';
	}



	return 0;
}