#include <iostream>

using namespace std;

int N, M;

int par[1000001];

int Find(int a) {
	if (par[a] == a) return a;
	else return par[a] = Find(par[a]);
}

void Union(int a, int b) {
	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA == rootB) return;

	par[rootB] = rootA;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) par[i] = i;

	for (int i = 0; i < M; i++) {
		int t, a, b;
		cin >> t >> a >> b;

		if (t == 0) Union(a, b);

		if (t == 1) {
			if (Find(a) == Find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}