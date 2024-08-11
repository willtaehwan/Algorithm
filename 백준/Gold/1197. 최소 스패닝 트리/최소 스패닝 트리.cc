#include <iostream>
#include <algorithm>

using namespace std;

struct Edge{
	int a;
	int b;
	int cost;

	bool operator<(Edge left) const {
		if (cost < left.cost) return true;
		else return false;
	}

};

int V, E;

Edge ed[100001];
int parent[10010];

int Find(int A) {
	if (parent[A] == A) return A;
	return parent[A] = Find(parent[A]);
}

void Union(int A, int B) {

	int rootA = Find(A);
	int rootB = Find(B);

	if (rootA == rootB) return;

	parent[rootA] = rootB;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		ed[i] = { a,b,c };
	}

	sort(ed, ed + E);

	//for (int i = 0; i < E; i++) cout << ed[i].cost << " ";
	//cout << '\n';

	for (int i = 0; i <= V; i++) parent[i] = i;

	int sum = 0;
	for (int i = 0; i < E; i++) {
		Edge now = ed[i];

		if (Find(now.a) == Find(now.b)) continue;

		Union(now.a, now.b);
		sum += now.cost;
	}

	cout << sum;

	return 0;
}