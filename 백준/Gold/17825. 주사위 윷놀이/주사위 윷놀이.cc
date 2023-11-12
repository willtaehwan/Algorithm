#include <iostream>
#include <vector>
using namespace std;

int map[15][27] = {
	{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40, 0,0,0,0,0,0},
	{0,0,0,0,0,13, 0, 0, 0, 0,22, 0, 0, 0, 0,28, 0, 0, 0, 0, 0, 0,0,0,0,0,0},
	{0,0,0,0,0,16, 0, 0, 0, 0,24, 0, 0, 0, 0,27, 0, 0, 0, 0, 0, 0,0,0,0,0,0},
	{0,0,0,0,0,19, 0, 0, 0, 0,25, 0, 0, 0, 0,26, 0, 0, 0, 0, 0, 0,0,0,0,0,0},
	{0,0,0,0,0,25, 0, 0, 0, 0,30, 0, 0, 0, 0,25, 0, 0, 0, 0, 0, 0,0,0,0,0,0},
	{0,0,0,0,0,30, 0, 0, 0, 0,35, 0, 0, 0, 0,30, 0, 0, 0, 0, 0, 0,0,0,0,0,0},
	{0,0,0,0,0,35, 0, 0, 0, 0,40, 0, 0, 0, 0,35, 0, 0, 0, 0, 0, 0,0,0,0,0,0},
	{0,0,0,0,0,40, 0, 0, 0, 0, 0, 0, 0, 0, 0,40, 0, 0, 0, 0, 0, 0,0,0,0,0,0},
	{0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0},
	{0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0},
	{0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0},
	{0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0},
	{0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0},
	{0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0},
	{0,0,0,0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0}
};

int colMap[10] = { 0, };
int pawnState[5] = { 0, };
int pawnMap[15][27] = { 0, };

int arr[10] = { 0, };

struct Node {
	int row;
	int col;
	int dir;
	int colM;
};

Node pawnPlace[5] = { 0, };

int sum = 0;
int maxResult = 0;

int path[10] = { 0, };

void dfs(int nowNum) {

	if (nowNum == 10) {
		//cout << "hi" << endl;
		/*if (sum > 187) {
			cout << "sum  :  " << sum << "    ";
			for (int i = 0; i < 10; i++) {
				cout << path[i] << " ";
			}
			cout << endl;
		}*/
		

		if (maxResult < sum) {
			maxResult = sum;
		}
		return;
	}

	for (int i = 1; i <= 4; i++) {
		if (pawnState[i] != 0) continue;
		Node now = pawnPlace[i];
		int ner = now.row;
		int nec = now.col;
		int ned = now.dir;
		int necm = now.colM;
		int flag = 0;

		if (now.dir == 0) {
			nec += arr[nowNum];
			//cout << " nec++ " << endl;
			if (map[ner][nec] == 40 && colMap[4] != 0) continue;
			if (pawnMap[ner][nec] != 0) continue;
			if (map[ner][nec] == 0) {
				//cout << nowNum << " " << i << " " << sum << endl;
				pawnState[i] = 1;
			}
			if (nec % 5 == 0 && nec < 20) ned = 1;
			
			pawnMap[now.row][now.col] = 0;
			if (now.colM != 0) colMap[now.colM] = 0;

			if (map[ner][nec] != 0) {
				if (map[ner][nec] == 40) {
					flag = 4;
					colMap[4] = 1;
					necm = 4;
				}
				pawnMap[ner][nec] = i;
				sum += map[ner][nec];
			}

			pawnPlace[i] = { ner,nec,ned,necm };
			path[nowNum] = map[ner][nec];
		}
		else {
			ner += arr[nowNum];
			//cout << " ner++ " << endl;
			
			if (pawnMap[ner][nec] != 0) continue;

			if (map[ner][nec] == 0) {
				//cout <<nowNum<<" "<< i <<" "<<sum<< endl;
				pawnState[i] = 1;
			}
			else {
				if (map[ner][nec] % 5 == 0) {
					flag = (map[ner][nec] - 20) / 5;
					if (colMap[flag] != 0) continue;
					else {
						colMap[flag] = 1;
						necm = flag;
					}
				}

				pawnMap[ner][nec] = i;
				sum += map[ner][nec];

			}

			if (now.colM != 0) colMap[now.colM] = 0;

			pawnMap[now.row][now.col] = 0;
			
			pawnPlace[i] = { ner,nec,ned,necm };
			path[nowNum] = map[ner][nec];
		}


		dfs(nowNum + 1);

		if (map[ner][nec] == 0) pawnState[i] = 0;
		if (now.colM != 0) colMap[now.colM] = now.colM;
		pawnPlace[i] = { now.row,now.col,now.dir,now.colM };
		sum -= map[ner][nec];
		
		pawnMap[ner][nec] = 0;
		pawnMap[now.row][now.col] = i;
		if (flag != 0) {
			colMap[flag] = 0;
		}

	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	dfs(0);

	cout << maxResult;

	return 0;
}