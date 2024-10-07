#include <iostream>

using namespace std;
int G, P, n, cnt;
int gate[100002];

int Find(int a) {
	if (gate[a] == a) return a;
	else return gate[a] = Find(gate[a]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> G >> P;
	for (int i = 1; i <= G; i++) gate[i] = i;
	for (int i = 0; i < P; i++) {
		cin >> n;
		int next = Find(n);
		if (next == 0) break;
		gate[next] = next - 1;
		cnt++;
	}
	cout << cnt;
	return 0;
}