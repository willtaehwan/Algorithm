#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node2 {
	int v;
	int i;

	bool operator<(Node2 right) const {
		if (v < right.v) return true;
		return false;
	}
};

struct Edge {
	int cost;
	int a;
	int b;

	bool operator<(Edge right) const {
		if (cost < right.cost) return true;
		return false;
	}
};

int N;


vector<Node2> v[3];
Edge edge[300060];
int par[100001];

int Find(int a) {
	if (par[a] == a) return a;
	return par[a] = Find(par[a]);
}

void Union(int a, int b) {
	int rootA = Find(a);
	int rootB = Find(b);
	if (rootA == rootB) return;
	par[rootB] = rootA;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[0].push_back({ x,i });
		v[1].push_back({ y,i });
		v[2].push_back({ z,i });
	}

	for (int i = 0; i < 3; i++) sort(v[i].begin(), v[i].end());
	for (int i = 0; i < N; i++) par[i] = i;

	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N-1; j++) {
			Node2 now = v[i][j];
			Node2 next = v[i][j + 1];
			int cost = next.v - now.v;
			edge[cnt++] = { cost, now.i, next.i };
		}
	}

	sort(edge, edge + cnt);

	int result = 0;
	for (int i = 0; i < cnt; i++) {
		Edge now = edge[i];
		if (Find(now.a) == Find(now.b)) continue;
		Union(now.a, now.b);
		result += now.cost;
	}

	cout << result;

	return 0;
}