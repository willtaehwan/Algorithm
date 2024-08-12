#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int N, M;

int map[1010][1010] = { 0, };

int max_result = 0;
void check(int row, int col) {

	if (!map[row][col]) return;
	//cout << row << " " << col << "  /  ";
	int temp1 = (int)sqrt(map[row - 1][col - 1]);
	int temp2 = (int)sqrt(map[row][col - 1]);
	int temp3 = (int)sqrt(map[row - 1][col]);
	
	int cnt = min(temp1, min(temp2,temp3)) + 1;
	
	map[row][col] = cnt * cnt;
	
	max_result = max(max_result, map[row][col]);
	//cout << max_result << "\n";
}

int main() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++) {
			map[i][j] = str[j-1] - '0';
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