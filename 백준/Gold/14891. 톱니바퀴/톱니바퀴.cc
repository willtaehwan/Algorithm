#include <iostream>
#include <cstring>
using namespace std;

int map[4][8] = { 0, };
int flag[3] = { 0, };

//2, 6
void turn(int num, int dir) {

	int temp;
	if (dir == 1) {
		temp = map[num][7];
		for (int i = 0; i < 7; i++) map[num][7 - i] = map[num][6 - i];
		map[num][0] = temp;
		if (num - 1 >= 0 && flag[num - 1] == 1) {
			flag[num - 1] = 0;
			turn(num - 1, -1);
		}
		if (num + 1 < 4 && flag[num] == 1) {
			flag[num] = 0;
			turn(num + 1, -1);
		}
	}
	else {
		temp = map[num][0];
		for (int i = 0; i < 7; i++) map[num][i] = map[num][i + 1];
		map[num][7] = temp;
		if (num - 1 >= 0 && flag[num - 1] == 1) {
			flag[num - 1] = 0;
			turn(num - 1, 1);
		}
		if (num + 1 < 4 && flag[num] == 1) {
			flag[num] = 0;
			turn(num + 1, 1);
		}
	}
}


int main() {

	for (int i = 0; i < 4; i++) {
		string row;
		cin >> row;

		for (int j = 0; j < 8; j++) {
			map[i][j] = int(row[j]-'0');
		}
	}

	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}*/

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int N, D;
		cin >> N >> D;
		memset(flag, 0, sizeof(flag));
		for (int j = 0; j < 3; j++) {
			if (map[j][2] != map[j + 1][6]) {
				flag[j] = 1;
			}
		}
		turn(N-1, D);
		/*cout << "====================="<<endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}*/
	}

	int sum = 0;
	int K[] = { 1,2,4,8 };

	for (int i = 0; i < 4; i++) {
		sum += map[i][0]*K[i];
	}
	cout << sum;
	


	return 0;
}