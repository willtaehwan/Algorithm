#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100002];
int parent[100002][18] = {0,};
int depth[100002] = { 0, };
int N, M;

int max_dep = 0;

int check(int a, int b) {

	if (a == 1 || b == 1) return 1;

	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) swap(a, b);
		for (int i = max_dep; i >= 0; i--) {
			if (depth[parent[b][i]] >= depth[a]) b = parent[b][i];
		}
	}
	int result = b;
	if (a != b) {
		for (int i = max_dep; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}
			result = parent[b][i];
		}
	}

	return result;
}

void set_tree(int now, int par, int dep) {

	depth[now] = dep;
	parent[now][0] = par;

	for (int i = 1; i <= max_dep; i++) {
		if (parent[now][i - 1] == 0) break;
		parent[now][i] = parent[parent[now][i - 1]][i - 1];
	}

	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		if (next == par) continue;
		set_tree(next, now, dep + 1);
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int temp = N;
	int cnt = 0;

	while (temp > 1) {
		temp = temp >> 1;
		cnt++;
	}
	max_dep = cnt;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	set_tree(1, 0, 0);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout<<check(a, b)<<'\n';
	}

	return 0;
}