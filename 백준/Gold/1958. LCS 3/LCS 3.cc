#include <iostream>

using namespace std;

int map[103][103][103] = {0,};

string row1, row2, row3;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> row1;
	cin >> row2;
	cin >> row3;
	
	int result = 0;

	int rl1 = row1.size();
	int rl2 = row2.size();
	int rl3 = row3.size();

	for (int i = 0; i < rl1; i++) {
		for (int j = 0; j < rl2; j++) {
			for (int k = 0; k < rl3; k++) {

				if (row1[i] == row2[j] && row1[i] == row3[k]) {
					map[i + 1][j + 1][k + 1] = map[i][j][k] + 1;
				}
				else {
					map[i + 1][j + 1][k + 1] = max(max(map[i][j+1][k+1], map[i+1][j][k+1]), map[i+1][j+1][k]);
				}

				result = max(result, map[i + 1][j + 1][k + 1]);
			}
		}
	}

	/*for (int i = 0; i <= rl1; i++) {
		for (int j = 0; j <= rl2; j++) {
			for (int k = 0; k <= rl3; k++) {
				cout << map[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}*/

	cout << result;

	return 0;
}