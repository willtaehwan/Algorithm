#include <iostream>

using namespace std;

struct Edge {
	int s;
	int e;
	int t;
};

int N, M, W;
Edge v[6001];
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
		
		for (int i = 2; i <= N; i++) dist[i] = 1e9;
		dist[1] = 0;
		/*cout << '\n';
		for (int i = 0; i < cnt; i++) cout << v[i].s << " " << v[i].e << " " << v[i].t << '\n';
		cout << '\n';*/
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < cnt; j++) {
				Edge now = v[j];
				//if (dist[now.s] == 1e9) continue;
				if (dist[now.e] > dist[now.s] + now.t) dist[now.e] = dist[now.s] + now.t;
			}
		}

		//for (int i = 1; i <= N; i++) cout << dist[i] << " ";
		//cout << '\n';

		bool flag = false;
		for (int i = 0; i < cnt; i++) {
			Edge now = v[i];
			//if (dist[now.s] == 1e9) continue;
			if (dist[now.e] > dist[now.s] + now.t) {
				flag = true;
				break;
			}
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";

	}


	return 0;
}