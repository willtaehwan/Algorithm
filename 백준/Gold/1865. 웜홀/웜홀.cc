#include <iostream>

using namespace std;

struct Edge {
	int s;
	int e;
	int t;
};

int N, M, W;
Edge v[5201];
int dist[502] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int TC;
	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		cin >> N >> M >> W;

		int cnt = 0;
		for (int i = 0; i < M + W; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			if (i < M) v[cnt++] = { e,s,t };
			else t *= -1;
			v[cnt++] = { s,e,t };
		}

		bool flag = false;
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < cnt; j++) {
				Edge now = v[j];
				if (dist[now.e] > dist[now.s] + now.t) {
					dist[now.e] = dist[now.s] + now.t;
					if (i == N) flag = true;
				}
			}
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";

	}


	return 0;
}