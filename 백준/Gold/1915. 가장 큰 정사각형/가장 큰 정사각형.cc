#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int N, M;

int map[1010][1010] = { 0, };
int saved[1010][1010] = { 0, };
int max_result = 0;
void check(int row, int col) {

	if (!map[row][col] || !map[row-1][col-1]) return;
	//cout << row << " " << col << "  /  ";
	int temp = (int)sqrt(saved[row - 1][col - 1]);
	//cout << temp<<"    /  ";
	bool flag = true;
	int cnt = 0;
	for (int i = 0; i <= temp; i++) {
		if (map[row - i][col] == 1 && map[row][col - i] == 1) cnt++;
		else break;
	}
	
	if (flag) saved[row][col] = cnt * cnt;
	
	max_result = max(max_result, saved[row][col]);
	//cout << max_result << "\n";
}

int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++) {
			map[i][j] = str[j-1] - '0';
			saved[i][j] = map[i][j];
			if (saved[i][j] == 1) max_result = 1;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			check(i, j);
			//cout << saved[i][j] << " ";
		}
		//cout << '\n';
	}

	

	cout << max_result;

	return 0;
}