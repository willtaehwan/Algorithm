#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int N, K;

int nmap[13][13] = { 0, };
int finishflag = 0;
int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };



struct pawn {
	int row;
	int col;
	int dir;
};

stack<int> vmap[13][13];
map<int,pawn> v;

void moveP(pawn p, int num) {

	int ner = p.row + dr[p.dir];
	int nec = p.col + dc[p.dir];
	
	stack<int> temp;
	//cout << ner << " " << nec << endl;
	
	if (nmap[ner][nec] == 2 || ner < 0 || nec < 0 || ner >= N || nec >= N) {
		int ned = p.dir;
		if (ned == 1) ned = 0;
		else if (ned == 0) ned = 1;
		else if (ned == 2) ned = 3;
		else ned = 2;
		ner = p.row + dr[ned];
		nec = p.col + dc[ned];
		//cout << ner << " / " << nec << " / " << ned<< endl;

		v[num] = { p.row,p.col,ned };
		
		if (nmap[ner][nec] == 2 || ner < 0 || nec < 0 || ner >= N || nec >= N) {
			//cout << "dd" << endl;
			return;
		}
		else {
			//cout << "gg" << endl;
			moveP({ p.row,p.col,ned },num);
		}
	}
	else if (nmap[ner][nec] == 1) {
		while (1) {
			int nowNum = vmap[p.row][p.col].top(); vmap[p.row][p.col].pop();

			vmap[ner][nec].push(nowNum);
			int ned = v[nowNum].dir;
			v[nowNum] = { ner,nec,ned };
			if (nowNum == num) break;

		}
	}
	else if (nmap[ner][nec] == 0) {
		//cout << "0" << endl;
		while (1) {
			int nowNum = vmap[p.row][p.col].top(); vmap[p.row][p.col].pop();
			temp.push(nowNum);
			if (nowNum == num) break;
		}

		while (!temp.empty()) {
			int next = temp.top(); temp.pop();
			vmap[ner][nec].push(next);
			//cout << ner << nec << v[next].dir << endl;
			int ned = v[next].dir;
			v[next] = { ner,nec,ned};
		}
	}


	if (vmap[ner][nec].size() >= 4) finishflag = 1;

	return;
}

int main() {

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> nmap[i][j];
		}
	}

	for (int i = 1; i <= K; i++) {
		int row, col, dir;
		cin >> row >> col >> dir;
		vmap[row - 1][col - 1].push(i);
		v.insert({ i,{ row - 1,col - 1,dir - 1} });
	}

	int cnt = 0;

	while (cnt < 1000) {
		//cout << endl;
		//cout << "cnt : " << cnt <<  endl;
		if (finishflag == 1) break;

		cnt++;
		for (auto it = v.begin(); it != v.end(); it++) {
			pawn now = it->second;
			int num = it->first;
			//cout <<"number : "<<num<<"  / " << now.row << " " << now.col << " " << now.dir << endl;
			moveP(now,num);
			/*cout << endl;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					cout << vmap[i][j].size() << " ";
				}
				cout << endl;
			}*/

		}
	}
	if (cnt == 1000) cout << -1;
	else cout << cnt;

	return 0;
}