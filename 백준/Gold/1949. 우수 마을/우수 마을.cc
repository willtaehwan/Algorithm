#include <iostream>
#include <vector>
using namespace std;

int N;
int w[10002];
bool visited[10002] = { 0, };
int DP[10002][2] = { 0, };

vector<int> v[10002];

void dp(int now) {

	DP[now][0] = w[now];
	visited[now] = true;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (visited[next]) continue;

		dp(next);

		DP[now][0] += DP[next][1];
		DP[now][1] += max(DP[next][0], DP[next][1]);
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> w[i];

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dp(1);

	cout << max(DP[1][0], DP[1][1]) << '\n';

	return 0;
}