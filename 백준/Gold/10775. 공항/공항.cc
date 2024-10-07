#include <iostream>

using namespace std;
int G, P, cnt;
int gate[100002];

int Find(int n) {
	if (gate[n] == n) return n;
	else return gate[n] = Find(gate[n]);
}

int check(int n) {
	int next = Find(n);
	gate[next] = next - 1;
	return next;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> G >> P;
	for (int i = 1; i <= G; i++) gate[i] = i;
	for (int i = 0; i < P; i++) {
		int n;
		cin >> n;
		if (!check(n))break;
		cnt++;
	}
	cout << cnt;
	return 0;
}