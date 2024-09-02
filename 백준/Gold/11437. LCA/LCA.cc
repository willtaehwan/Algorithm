#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[50002];
int parent[50002] = { 0, };
int depth[50002] = { 0, };
int N, M;

int check(int a, int b) {

	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) swap(a, b);
		while (depth[a] != depth[b]) b = parent[b];
	}

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
}

void set_tree(int now, int par) {

	parent[now] = par;
	depth[now] = depth[par] + 1;

	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		if (next == par) continue;
		set_tree(next, now);
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	set_tree(1, 0);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout<<check(a, b)<<'\n';
	}

	return 0;
}