#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
	int cnt;
	int bit;
	int fish;
	int prev;
};

int M, S;

int map[4][4][8];
int temp[4][4][8];
int temp_fish[4][4][8];
int now_fish[4][4];
int smell[4][4];
Node shark;

int dr[] = { -1,-1,0,1,1,1,0,-1 };
int dc[] = { 0,-1,-1,-1,0,1,1,1 };

void rep_ready() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			now_fish[i][j] = 0;
			for (int k = 0; k < 8; k++) {
				temp[i][j][k] = map[i][j][k];
				temp_fish[i][j][k] = 0;
			}
		}
	}
}

void fish_move(int row, int col, int dir) {

	bool flag = true;

	for (int i = 0; i < 8; i++) {
		int ned = (dir + i) % 8;
		int ner = row + dr[ned];
		int nec = col + dc[ned];
		if (ner < 0 || nec < 0 || ner >= 4 || nec >= 4) continue;
		if (smell[ner][nec] != 0) continue;
		if (ner == shark.row && nec == shark.col) continue;

		temp_fish[ner][nec][ned] += map[row][col][dir];
		now_fish[ner][nec] += map[row][col][dir];
		flag = false;
		break;
	}

	if (flag) {
		temp_fish[row][col][dir] += map[row][col][dir];
		now_fish[row][col] += map[row][col][dir];
	}

}

void shark_move() {
	//int visited[4][4] = { -1, };

	queue<Node> q;
	q.push(shark);
	int max_fish = 0;
	int prior = 65;
	int bbi = 0;
	while (!q.empty()) {
		Node now = q.front(); q.pop();

		if (now.cnt == 3) {
			if (max_fish < now.fish) {
				max_fish = now.fish;
				prior = now.bit;
				bbi = now.prev;
			}
			else if (max_fish == now.fish && prior > now.bit) {
				prior = now.bit;
				bbi = now.prev;
			}
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i * 2];
			int nec = now.col + dc[i * 2];
			if (ner < 0 || nec < 0 || ner >= 4 || nec >= 4) continue;
			
			int next = now.fish + now_fish[ner][nec];
			//cout << ner << ", " << nec << "   "<<visited[ner][nec]<<", "<<next<<"\n";
			//if (visited[ner][nec] > next) continue;
			
			//visited[ner][nec] = next;
			
			//cout << now.bit << ", " << i<<" : ";
			int neb = (now.bit << 2) + i;
			//cout << neb << '\n';
			//cout << now.prev << " : " << (1 << (ner * 4 + nec)) << '\n';
			if (now.prev & (1 << (ner * 4 + nec))) {
				next = now.fish;
			}

			int stat_check = now.prev | (1 << (ner * 4 + nec));
			q.push({ ner,nec,now.cnt + 1,neb, next, stat_check });
		}

	}
	//cout << prior << " - "<< max_fish << "\n";
	//cout <<"perperpeprp"    << bbi << "\n";
	for (int i = 2; i >=0; i--) {
		int ned = ((prior >> i*2) & 3);
		//cout << ned << '\n';
		
		int ner = shark.row + dr[ned * 2];
		int nec = shark.col + dc[ned * 2];
		
		for (int j = 0; j < 8; j++)map[ner][nec][j] = 0;

		if (now_fish[ner][nec] != 0) {
			smell[ner][nec] = 3;
			now_fish[ner][nec] = 0;
		}
		shark = { ner,nec, 0, 0,0, 0 };
	}

}

void rep_on() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 8; k++) {
				map[i][j][k] += temp[i][j][k];
				now_fish[i][j] += temp[i][j][k];
				temp[i][j][k] = 0;
			}
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> M >> S;

	for (int i = 0; i < M; i++) {
		int r, c, d;
		cin >> r >> c >> d;
		d = (11 - d) % 8;
		map[r-1][c-1][d]++;
	}
	
	int sh_r, sh_c;
	cin >> sh_r >> sh_c;
	shark = { sh_r - 1, sh_c - 1, 0, 0,0, 0 };

	

	for (int s = 0; s < S; s++) {
		rep_ready();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 8; k++) {
					if (map[i][j][k] == 0) continue;
					fish_move(i, j, k);
				}
			}
		}
		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 8; k++) {
					map[i][j][k] = temp_fish[i][j][k];
				}
			}
		}

		/*for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 8; k++) {
					cout << map[i][j][k];
				}
				cout << " ";
			}
			cout << '\n';
		}
		cout << '\n';*/

		
		shark_move();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (smell[i][j] != 0) smell[i][j]--;
			}
		}

		rep_on();
		
		/*cout << "now_fish============================\n";
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << now_fish[i][j] << " ";
			}
			cout << '\n';
		}
		cout << '\n';

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 8; k++) {
					cout << map[i][j][k];
				}
				cout << " ";
			}
			cout << '\n';
		}
		cout << '\n';
		cout << "smell========================\n";
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << smell[i][j] << " ";
			}
			cout << '\n';
		}
		cout << '\n';
		
		
		cout << shark.row << " " << shark.col << '\n';


		cout << "loop end===============================================\n";*/
	}

	int result = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			//cout << now_fish[i][j] << " ";
			result += now_fish[i][j];
		}
		//cout << '\n';
	}
	
	

	cout << result;

	return 0;
}