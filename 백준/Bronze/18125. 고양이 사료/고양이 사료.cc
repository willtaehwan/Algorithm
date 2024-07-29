#include <iostream>

using namespace std;

int R, C;

int map[101][101];
int tmap[101][101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> C >> R;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			cin >> tmap[i][j];
		}
	}
	bool flag = true;
	for (int i = 0; i < R; i++) {
		if (!flag) break;
		for (int j = 0; j < C; j++) {
			if (map[i][j] != tmap[j][R-i-1]) {
				flag = false;
				break;
			}
		}
	}

	if (flag) {
		cout << "|>___/|        /}\n";
		cout << "| O < |       / }\n";
		cout << "(==0==)------/ }\n";
		cout << "| ^  _____    |\n";
		cout << "|_|_/     ||__|\n";
	}
	else {
		cout << "|>___/|     /}\n";
		cout << "| O O |    / }\n";
		cout << "( =0= )\"\"\"\"  \\\n";
		cout << "| ^  ____    |\n";
		cout << "|_|_/    ||__|\n";
	}

	return 0;
}