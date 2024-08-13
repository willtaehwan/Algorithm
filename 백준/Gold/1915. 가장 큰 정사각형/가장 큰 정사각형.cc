#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int N, M;

int map[2][1010] = { 0, };

int max_result = 0;
void check(int row, int col) {

	if (!map[row][col]) return;
	int temp1 = (int)sqrt(map[!row][col - 1]);
	int temp2 = (int)sqrt(map[row][col - 1]);
	int temp3 = (int)sqrt(map[!row][col]);
	
	int cnt = min(temp1, min(temp2,temp3)) + 1;
	
	map[row][col] = cnt * cnt;
	
	max_result = max(max_result, map[row][col]);

}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= M; j++) {
			map[i%2][j] = str[j-1] - '0';
			check(i%2, j);
		}
	}

	cout << max_result;

	return 0;
}