#include <iostream>
using namespace std;

int N;

int arr[100002] = { 0, };
bool check[100002] = { 0, };
int visited[100002] = { 0, };
int path[100002] = { 0, };
int ans = 0;

void dfs(int now, int cnt) {

	if (check[now]) return;

	if (visited[now] != 0) {
		ans += cnt - visited[now];
		return;
	}

	visited[now] = cnt;
	dfs(arr[now], cnt + 1);
	check[now] = true;
	visited[now] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		ans = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			check[i] = false;
		}
		for (int i = 1; i <= N; i++) dfs(i, 1);

		cout << N - ans<<'\n';
	}

	return 0;
}