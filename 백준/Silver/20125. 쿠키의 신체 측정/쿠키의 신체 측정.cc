#include <iostream>

using namespace std;

int N;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int hx = -1, hy = -1;
	int la = 0, ra = 0, ll = 0, rl = 0, hr = -1;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char now;
			cin >> now;

			if (now == '*' && !flag) {
				hx = i + 1;
				hy = j;
				flag = true;
				continue;
			}

			if (now == '*') {
				if (j < hy) {
					if (i == hx) la++;
					else ll++;
				}
				if (j > hy) {
					if (i == hx) ra++;
					else rl++;
				}
				if (j == hy) hr++;

			}

		}
	}

	cout << hx+1 << " " << hy+1 << '\n';
	cout << la << " " << ra << " " << hr << " " << ll << " " << rl;

	return 0;
}