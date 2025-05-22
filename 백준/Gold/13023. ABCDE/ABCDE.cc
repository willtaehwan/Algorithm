#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v[2001];
bool visited[2001] = { 0, };
bool flag = false;

void dfs(int now, int cnt) {
	if (flag) return;
	
	if (cnt == 5) {
		flag = true;
		return;
	}

	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];

		if (visited[next]) continue;
		visited[next] = true;
		dfs(next, cnt + 1);
		visited[next] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		visited[i] = true;
		dfs(i, 1);
		visited[i] = false;
	}

	if (flag) cout << 1;
	else cout << 0;

	return 0;
}