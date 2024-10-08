#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

struct Node {
	int row;
	int col;
};

struct Edge {
	int cost;
	int a;
	int b;

	bool operator<(Edge right) const {
		if (cost < right.cost) return true;
		else return false;
	}
};

int N;

Node star[101];
Edge line[5000];

int par[101] = { 0, };

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

	cin >> N;

	for (int i = 0; i < N; i++) {
		float a, b;
		cin >> a >> b;
		star[i].row = a * 100;
		star[i].col = b * 100;
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			int dist;
			ll row = abs(star[i].row - star[j].row);
			ll col = abs(star[i].col - star[j].col);

			dist = (int)sqrt(row * row + col * col);
			line[cnt++] = { dist, i, j };
		}
	}

	for (int i = 0; i < N; i++) par[i] = i;

	sort(line, line + cnt);
	int result = 0;
	for (int i = 0; i < cnt; i++) {
		Edge now = line[i];

		if (Find(now.a) == Find(now.b)) continue;
		Union(now.a, now.b);
		result += now.cost;
	}
	cout << result/100<<"."<<result%100;

	return 0;
}