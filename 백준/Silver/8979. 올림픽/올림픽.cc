#include <iostream>

using namespace std;

int N, K;

struct medal {
	int gold;
	int silver;
	int bronze;
};

medal m[1001];

int main() {

	cin >> N >> K;

	int rank = 1;

	for (int i = 1; i <= N; i++) {
		int con;
		cin >> con;
		cin >> m[con].gold >> m[con].silver >> m[con].bronze;
	}
	

	for (int i = 1; i <= N; i++) {
		if (m[i].gold > m[K].gold) rank++;
		else if (m[i].gold == m[i].gold) {
			if (m[i].silver > m[K].silver) rank++;
			else if (m[i].silver == m[K].silver) {
				if (m[i].bronze > m[K].bronze) rank++;
			}
		}
	}

	cout << rank;

	return 0;
}