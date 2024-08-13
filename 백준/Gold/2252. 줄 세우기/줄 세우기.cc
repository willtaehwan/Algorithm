#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int degree[32010] = { 0, };

vector<int> v[32010];

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		degree[b]++;
	}

	queue<int> q;
	queue<int> result;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
	
		result.push(now);
			
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (degree[next] > 1) degree[next]--;
			else q.push(next);
		}
	}

	while (!result.empty()) {
		int now = result.front(); result.pop();
		cout << now <<" ";
	}


	return 0;
}