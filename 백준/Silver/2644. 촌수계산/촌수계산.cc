#include <iostream>
#include <vector>
using namespace std;

vector<int> v[101];

int visited[101] = { 0, };

int n, a, b, m;
int flag = 0;
void dfs(int now) {

	if (now == b) {
		cout << visited[now]-1;
		flag = 1;
		return;
	}

	

	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];

		if (flag == 1) {
			break;
		}

		if (visited[next] != 0) {
			continue;
		}

		visited[next] = visited[now] + 1;

		dfs(next);

		visited[next] = 0;

	}

}

int main() {

	

	cin >> n >> a >> b >> m;

	for (int i = 0; i < m; i++) {
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}

	visited[a] = 1;
	dfs(a);

	if (flag == 0) {
		cout << -1;
	}

	return 0;
}