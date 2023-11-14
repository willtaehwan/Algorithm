#include <iostream>

using namespace std;

struct Fish {
	int num;
	int dir;
};

struct Node {
	int row;
	int col;
};

Fish map[4][4];

Node fish[17];
Node shark = { 0, };
int dr[] = { -1,-1,0,1,1,1,0,-1 };
int dc[] = { 0,-1,-1,-1,0,1,1,1 };

int sum = 0;
int maxResult = 0;
void fishMove() {
	/*cout << "#########################" << endl;
	for (int i = 1; i <= 16; i++) {
		cout << fish[i].row << " " << fish[i].col << endl;
	}
	cout <<"#########################" << endl;*/

//17 10 0 0
//11 14 7 0
//13 0 12 8
//4 15 16 9
//
//4 2 0 0
//4 0 0 0
//6 0 6 0
//4 6 0 6


	for (int i = 1; i <= 16; i++) {
		if (fish[i].row == -1) continue;
		
		//cout << num << endl;
		Node now = fish[i];
		Fish nowN = map[now.row][now.col];
		//cout << i<<" : "<< now.row << " " << now.col << "  ->  ";
		int ned = map[now.row][now.col].dir - 1;
		int ner = 0;
		int nec = 0;
		while (1) {
			
			//cout << "nonono" << endl;
			ned++;
			ned = ned % 8;

			ner = now.row + dr[ned];
			nec = now.col + dc[ned];
			//cout << ner<<" + "<<dr[ned]<<" / "<< nec<<" + " << dc[ned]<<" "<<ned << endl;
			if (ner < 0 || nec < 0 || ner >= 4 || nec >= 4) continue;
			if (map[ner][nec].num == 17) continue;
			//cout << now.row << " " << now.col << endl;
			//cout << ner << " " << nec << endl;
			map[now.row][now.col] = map[ner][nec];
			map[ner][nec] = nowN;
			map[ner][nec].dir = ned;
			fish[map[now.row][now.col].num] = { now.row,now.col };
			fish[map[ner][nec].num] = { ner,nec };
			//cout << ner << " " <<nec<< endl;
			break;

		}

	}

	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << map[i][j].num << " ";
		}
		cout << endl;
	}
	cout << endl;*/



	return;
}

void sharkMove() {

	
	Node now = shark;
	int ned = map[now.row][now.col].dir;

	for (int i = 0; i < 3; i++) {
		int ner = now.row + dr[ned] + dr[ned]*i;
		int nec = now.col + dc[ned] + dc[ned]*i;
		int nextNum = map[ner][nec].num;
		if (ner < 0 || nec < 0 || ner>=4 || nec >= 4) {
			//cout << " sum = " << sum << endl;
			if (maxResult < sum) {
				maxResult = sum;
			}

			return;
		}
		if (nextNum == 0) continue;

		map[now.row][now.col] = { 0,0 };
		shark = { ner,nec };
		sum += nextNum;
		Node tteemmpp = fish[nextNum];
		fish[nextNum] = { -1,-1 };
		map[ner][nec].num = 17;
		
		Fish tempMap[4][4];
		//cout << "=======================================" << endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				tempMap[i][j] = map[i][j];
				//cout << tempMap[i][j].num << " ";
			}
			//cout << endl;
		}
		//cout << endl;
		/*for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << tempMap[i][j].dir << " ";
			}
			cout << endl;
		}*/
		Node tempFish[17];
		for (int k = 1; k <= 16; k++) tempFish[k] = fish[k];

		/*cout << "=========================================" << endl;
		cout << " ner / nec = " << ner << " " << nec << endl;*/

		fishMove();
		sharkMove();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				map[i][j] = tempMap[i][j];
			}
		}

		for (int k = 1; k <= 16; k++) fish[k] = tempFish[k];
		fish[nextNum] = tteemmpp;
		map[now.row][now.col] = { 17,ned };
		shark = { now.row, now.col };
		sum -= nextNum;
		map[ner][nec].num = nextNum;

	}


}



int main() {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			map[i][j] = { a,b-1 };
			fish[a] = { i,j };
		}
	}

	fish[map[0][0].num] = { -1,-1 };
	sum += map[0][0].num;
	map[0][0].num = 17;

	
	fishMove();
	sharkMove();

	cout << maxResult;

	return 0;
}