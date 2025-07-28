#include <iostream>

using namespace std;

int lev[5];
int tot = 0;
bool flag = true;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 0; i < 5; i++) cin >> lev[i];
	int e = 0;
	int m = 2;
	int h = 4;
	while (flag) {

		if (lev[e] == 0) {
			if (e == 1 || lev[1] == 0) flag = false;
			else e++;
		}
		lev[e]--;

		if (lev[2] == 0) {
			if (lev[1] || lev[3]) {
				if (lev[1] >= lev[3]) m = 1;
				else m = 3;
			}
			else flag = false;
		}
		lev[m]--;

		if (lev[h] == 0) {
			if (h == 3 || lev[3] == 0) flag = false;
			else h--;
		}
		lev[h]--;

		if (flag) tot++;
	}

	cout << tot;

	return 0;
}