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
		visited[now] = true;
		dfs(next, cnt + 1);
		visited[now] = false;
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

	for (int i = 0; i < N; i++) dfs(i, 1);

	cout << flag;

	return 0;
}