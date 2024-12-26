#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int to;
	long long cost;
};

int N, M;

vector<Node> v[100020];
int depth[100020] = { 0, };
int parent[100020][20] = {0,};
long long par_cost[100020] = { 0, };

int max_dep = 18;

int search_k(int a, int b, int lca, int k) {

	int a_dep = depth[a] - depth[lca];
	int b_dep = depth[b] - depth[lca];

	if (a_dep + 1 > k) {

		k -= 1;
		int ne = 0;
		while (k > 0) {
			if (k & 1) a = parent[a][ne];
			ne++;
			k = k >> 1;
		}
		return a;
	}
	else if (a_dep + 1 < k) {
		k = b_dep - (k - (a_dep + 1));
		int ne = 0;
		while (k > 0) {
			if (k & 1) b = parent[b][ne];
			ne++;
			k = k >> 1;
		}

		return b;
	}
	else return lca;
}

int search_dep(int a, int b) {
	
	if (a == 1 || b == 1) return 1;

	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) swap(a, b);
		for (int i = max_dep; i >= 0; i--) {
			if (depth[parent[b][i]] >= depth[a]) b = parent[b][i];
		}
	}

	int lca = b;

	if (a != b) {
		for (int i = max_dep; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}

			lca = parent[b][i];
		}
	}

	return lca;
}

void set_tree(int now, int par, int dep) {

	depth[now] = dep;
	parent[now][0] = par;

	for (int i = 1; i <= max_dep; i++) {
		if (parent[now][i - 1] == 0) break;
		parent[now][i] = parent[parent[now][i - 1]][i - 1];
	}

	for (int i = 0; i < v[now].size(); i++) {
		if (v[now][i].to == par) {
			par_cost[now] = v[now][i].cost + par_cost[par];
			break;
		}
	}

	for (int i = 0; i < v[now].size(); i++) {
		Node next = v[now][i];
		if (next.to == par) continue;
		set_tree(next.to, now, dep + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;


	for (int i = 0; i < N - 1; i++) {
		int  a, b, w;
		cin >> a >> b >> w;
		v[a].push_back({ b, w });
		v[b].push_back({ a, w });
	}

	set_tree(1, 0, 0);

	//for (int i = 1; i <= N; i++) cout << par_cost[i] << " ";
	//cout << '\n';
	cin >> M;

	for (int i = 0; i < M; i++) {
		int num, a, b;
		int k = 0;
		cin >> num >> a >> b;
		int lca = search_dep(a, b);
		if (num == 1) {
			long long result = par_cost[a] + par_cost[b] - par_cost[lca] - par_cost[lca];
			cout << result << '\n';
		}
		else {
			cin >> k;
			cout << search_k(a, b, lca, k)<<'\n';
		}
	}

	return 0;
}