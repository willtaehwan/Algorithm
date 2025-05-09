#include <iostream>
#include <vector>
using namespace std;

vector<int> v[51];
int N, M;
int cnt = 0;


void dfs(int now) {
	bool flag = false;

	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (next == M) continue;
		flag = true;
		dfs(next);
	}

	if (!flag && now != 0) cnt++;
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		v[a + 1].push_back(i);
	}

	cin >> M;
	M++;
	dfs(0);
	cout << cnt;

	return 0;
}