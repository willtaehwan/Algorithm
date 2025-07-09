#include <iostream>

using namespace std;

int N, M, Q;

int par[1002] = { 0, };

int Find(int a) {
	if (par[a] == a) return a;
	return Find(par[a]);
}

void Union(int a, int b) {

	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA == rootB) return;

	par[rootB] = rootA;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> Q;

	for (int i = 1; i <= N; i++) par[i] = i;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		Union(a, b);
	}

	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;

		if (Find(a) == Find(b)) cout << "Y\n";
		else cout << "N\n";
	}


	return 0;
}