#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
	int row;
	int col;
};

struct Edge {
	double cost;
	int a;
	int b;

	bool operator<(Edge right) {
		if (cost < right.cost) return true;
		return false;
	}
};

int N, M;

Node node[1010];
int par[1010];
Edge edge[500000];

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
	cin >> N >> M;

	for (int i = 1; i <= N; i++) cin >> node[i].row >> node[i].col;
	for (int i = 1; i <= N; i++) par[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			double ans = sqrt(pow(node[i].row - node[j].row, 2) + pow(node[i].col - node[j].col, 2));
			edge[cnt++] = { ans,i,j };
		}
	}

	sort(edge, edge + cnt);

	double result = 0;
	for (int i = 0; i < cnt; i++) {
		Edge now = edge[i];

		if (Find(now.a) == Find(now.b)) continue;
		Union(now.a, now.b);
		result += now.cost;
		//cout << now.cost << " , " << now.a << ", " << now.b << '\n';
	}
	cout << fixed;
	cout.precision(2);
	cout << result;
	
	return 0;
}