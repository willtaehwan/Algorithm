#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

vector<int> v[101];

int dk(int stnow) {
	int dist[101] = { 0, };

	for (int i = 1; i <= N; i++) {
		dist[i] = 1e9;
	}

	queue<int> q;
	q.push(stnow);
	dist[stnow] = 0;

	while (!q.empty()) {
		int now = q.front(); q.pop();



		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];

			if (dist[next] <= dist[now] + 1) continue;

			dist[next] = dist[now] + 1;

			q.push(next);

		}
	}
	int sum = 0;
	for(int i = 1; i<=N;i++){
		sum += dist[i];
	}
	return sum;
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	int min_Root = 1e9;
	int pNum;
	for (int i = 1; i <=N; i++) {
		int ans = dk(i);
		//cout << ans << endl;
		if (min_Root > ans) {
			min_Root = ans;
			pNum = i;
		}
	}

	cout << pNum;
	return 0;
}