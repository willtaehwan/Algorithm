#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;

vector<int> v[100004];
int par[100004];

int dfs(int now, int prev) {

	int result = 1;

	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (next == prev) continue;
		result += dfs(next, now);
	}
	par[now] = result;
	return result;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> R >> Q;
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(R, 0);

	//for (int i = 1; i <= N; i++) cout << par[i] << " ";

	for (int i = 0; i < Q; i++) {
		int q;
		cin >> q;
		cout << par[q] << "\n";
	}

	return 0;
}