#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[11];

int pe[11] = { 0, };
int N;
int visited[11] = { 0, };

int bfs(int a, bool d) {

	for (int i = 1; i <= N; i++) visited[i] = -1;

	int st = 0;
	for (int i = 1; i <= N; i++) {
		if ((a & 1) == d) {
			visited[i] = 0;
			st = i;
		}
		a /= 2;
	}
	
	queue<int> q;
	q.push(st);
	visited[st] = 1;

	while (!q.empty()) {
		int now = q.front(); q.pop();
		
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];

			if (visited[next] != 0) continue;
			visited[next] = 1;
			q.push(next);
		}
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) return 1e9;
		else if (visited[i] == 1) sum += pe[i];
	}

	return sum;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> pe[i];

	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			v[i].push_back(b);
		}
	}
	int n = 1;

	for (int i = 0; i < N; i++) n *= 2;
	
	int mr = 1e9;
	for (int i = 1; i < n-1; i++) {
		int A = bfs(i, 0);
		int B = bfs(i, 1);
		if (A + B >= 1e9) continue;
		mr = min(mr, abs(A - B));
	}

	if (mr == 1e9) cout << -1;
	else cout << mr;

	return 0;
}