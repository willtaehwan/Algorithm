#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int arr[102] = { 0, };
bool check[102] = { 0, };
int visited[102] = { 0, };
int path[102] = { 0, };
int ans = 0;

void dfs(int now, int cnt) {

	if (check[now]) return;

	if (visited[now] != 0) {
		for (int i = visited[now]; i < cnt; i++) {
			check[path[i]] = true;
			ans++;
		}
		return;
	}

	visited[now] = cnt;
	path[cnt] = now;
	dfs(arr[now], cnt + 1);
	path[cnt] = 0;
	visited[now] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> arr[i];

	for (int i = 1; i <= N; i++) dfs(i, 1);

	cout << ans<<'\n';
	for (int i = 1; i <= N; i++) {
		if (check[i]) cout << i << '\n';
	}

	return 0;
}