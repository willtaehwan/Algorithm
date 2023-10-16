#include <iostream>

using namespace std;

int N;

int map[25][25] = { 0, };

int newMap[25][25] = { 0, };

int result = 0;

int MapChange() {

	int flag = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//cout << newMap[i][j]<<" ";
			if (map[i][j] != newMap[i][j]) flag = 1;
		}
		//cout << endl;
	}
	//cout << endl;
	if (flag == 0) return 0;
	else return 1;

}

void checkMapLeft() {

	for (int i = 0; i < N; i++) {

		int nowNum = 0;
		int flag = 0;
		int temp = 0;
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0){
				if (flag == 0) {
					temp = map[i][j];
					flag = 1;
				}
				else {
					if (temp == map[i][j]) {
						newMap[i][nowNum] = temp * 2;
						temp = 0;
						flag = 0;
					}
					else {
						newMap[i][nowNum] = temp;
						temp = map[i][j];
					}
					nowNum++;
				}
			}
		}

		newMap[i][nowNum] = temp;

	}
	//cout << "===LEFT===" << endl;
	
}

void checkMapRight() {

	for (int i = 0; i < N; i++) {

		int nowNum = N-1;
		int flag = 0;
		int temp = 0;
		for (int j = N-1; j >= 0; j--) {
			if (map[i][j] != 0) {
				if (flag == 0) {
					temp = map[i][j];
					flag = 1;
				}
				else {
					if (temp == map[i][j]) {
						newMap[i][nowNum] = temp * 2;
						temp = 0;
						flag = 0;
					}
					else {
						newMap[i][nowNum] = temp;
						temp = map[i][j];
					}
					nowNum--;
				}
			}
		}

		newMap[i][nowNum] = temp;

	}

	//cout << "===RIGHT===" << endl;

}

void checkMapUp() {

	for (int j = 0; j < N; j++) {

		int nowNum = 0;
		int flag = 0;
		int temp = 0;
		for (int i = 0; i < N; i++) {
			if (map[i][j] != 0) {
				if (flag == 0) {
					temp = map[i][j];
					flag = 1;
				}
				else {
					if (temp == map[i][j]) {
						newMap[nowNum][j] = temp * 2;
						temp = 0;
						flag = 0;
					}
					else {
						newMap[nowNum][j] = temp;
						temp = map[i][j];
					}
					nowNum++;
				}
			}
		}

		newMap[nowNum][j] = temp;
	}

	//cout << "===UP===" << endl;

}

void checkMapDown() {

	for (int j = 0; j < N; j++) {

		int nowNum = N-1;
		int flag = 0;
		int temp = 0;
		for (int i = N-1; i >= 0; i--) {
			if (map[i][j] != 0) {
				if (flag == 0) {
					temp = map[i][j];
					flag = 1;
				}
				else {
					if (temp == map[i][j]) {
						newMap[nowNum][j] = temp * 2;
						temp = 0;
						flag = 0;
					}
					else {
						newMap[nowNum][j] = temp;
						temp = map[i][j];
					}
					nowNum--;
				}
			}
		}

		newMap[nowNum][j] = temp;
	}

	//cout << "===DOWN===" << endl;
}

void dfs(int now){

	if (now >= 5) {
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > result) {
					result = map[i][j];
				}
			}
		}

		return;
	}

	for (int i = 0; i < 4; i++) {
		int nowMap[25][25] = {0, };

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				nowMap[i][j] = map[i][j];

			}
		}

		
		if (i == 0) checkMapUp();
		else if (i == 1) checkMapDown();
		else if (i == 2) checkMapLeft();
		else checkMapRight();

		int result = MapChange();
		
		//cout << result << endl;
		if (result == 0) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					newMap[i][j] = 0;
				}
			}
			continue;
		}
		//cout << "==OK==" << endl;
		//cout << " == //" << now << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = newMap[i][j];
				newMap[i][j] = 0;
				//cout << map[i][j] << " ";
			}
			//cout << endl;
		}
		//cout << endl;

		dfs(now + 1);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = nowMap[i][j];
			}
		}


	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// 5회 이동 최대값
	// 경우의 수 = 5 * 4 = 20
	if (N == 1) result = map[0][0];
	else dfs(0);

	cout << result;

	return 0;
}