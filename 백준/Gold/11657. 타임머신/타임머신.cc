#include <iostream>
#define MAX 987654321
using namespace std;

int N, M;

struct Edge {
	int st;
	int end;
	int cost;
};

Edge ed[6010];
long long dist[510];

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		ed[i] = { a,b,c };
	}

	for (int i = 2; i <= N; i++) dist[i] = MAX;

	dist[1] = 0;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			Edge now = ed[j];
			if (dist[now.st] == MAX) continue;
			if (dist[now.end] > dist[now.st] + now.cost) dist[now.end] = dist[now.st] + now.cost;
		}
	}

	bool flag = false;
	for (int i = 0; i < M; i++) {
		Edge now = ed[i];
		if (dist[now.st] == MAX) continue;
		if (dist[now.end] > dist[now.st] + now.cost) {
			flag = true;
			break;
		}
	}

	if (flag) cout << -1<<'\n';
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == MAX) cout << -1 << '\n';
			else cout << dist[i] << '\n';
		}
	}
	

	return 0;
}