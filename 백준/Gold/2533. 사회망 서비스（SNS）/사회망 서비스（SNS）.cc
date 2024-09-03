#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

vector<int> adj[1000002];
int dp[1000002][2];

void setTree(int now, int par) {

	
	dp[now][1] = 1;

	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		if (next == par) continue;
		setTree(next, now);
		dp[now][0] += dp[next][1];
		dp[now][1] += min(dp[next][0], dp[next][1]);
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	setTree(1, 0);

	cout << min(dp[1][0], dp[1][1]);

	return 0;
}