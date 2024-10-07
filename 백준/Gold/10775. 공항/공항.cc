#include <iostream>

using namespace std;

int G, P, cnt;

int gate[100002];

int Find(int n) {
	if (gate[n] == n) return n;
	else return gate[n] = Find(gate[n]);
}

bool check(int n) {
	int next = Find(n);
	//cout << n << ", " << next << '\n';
	if (next == 0) return false;
	else {
		int ne = Find(next - 1);
		gate[n] = ne;
		gate[next] = ne;
		return true;
	}

	
}

int main() {

	cin >> G >> P;
	for (int i = 1; i <= G; i++) gate[i] = i;

	for (int i = 0; i < P; i++) {
		int n;
		cin >> n;
		if (!check(n))break;

		//for (int i = 1; i <= G; i++) cout << gate[i] << " ";
		//cout << '\n';

		cnt++;
	}
	cout << cnt;
	return 0;
}