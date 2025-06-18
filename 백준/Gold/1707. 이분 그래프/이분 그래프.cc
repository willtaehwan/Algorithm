#include <iostream>
#include <vector>
using namespace std;

int T, V, E;

vector<int> v[20001];

int visited[20001] = { 0, };
bool flag = true;

void dfs(int now) {

	if (!flag) return;

	for (int i = 0; i < v[now].size(); i++){
		int next = v[now][i];
		
		if (visited[next] == -1) {
			visited[next] = (visited[now] + 1) % 2;
			dfs(next);
		}

		if (visited[next] == visited[now]) flag = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> V >> E;
		flag = true;
		for (int i = 1; i <= V; i++) {
			visited[i] = -1;
			v[i].clear();
		}

		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		for (int i = 1; i <= V; i++) {
			if (visited[i] != -1) continue;
			visited[i] = 0;
			dfs(i);
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";

	}




	return 0;
}