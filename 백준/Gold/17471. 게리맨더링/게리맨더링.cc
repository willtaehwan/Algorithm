#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[11];

int pe[11] = { 0, };
int N;
int visited[11] = { 0, };

bool bfs(int a, bool d) {

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

	bool flag = true;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) flag = false;
	}

	return flag;
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
	
	int min_result = 1e9;
	for (int i = 1; i < n-1; i++) {
		if (bfs(i, 0) && bfs(i, 1)) {
			int gA = 0, gB = 0;
			int tmp = i;
			for (int j = 1; j <= N; j++) {
				if ((tmp & 1) == true) gA += pe[j];
				else gB += pe[j];
				tmp /= 2;
			}
			min_result = min(min_result, abs(gA - gB));
		}
	}
	if (min_result == 1e9) cout << -1;
	else cout << min_result;

	return 0;
}