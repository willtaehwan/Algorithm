#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> v;
int path[8] = { 0, };
int cnt = 0;
int DAT[10001] = { 0, };

void dfs(int now, int prev) {

	if (now >= M) {
		for(int i = 0; i<M;i++) cout << path[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		int next = v[i];
		if (next < prev) continue;

		path[cnt++] = next;
		dfs(now + 1, next);
		path[--cnt] = 0;
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (DAT[a] == 0) {
			v.push_back(a);
			DAT[a] = 1;
		}
	}

	sort(v.begin(), v.end());

	dfs(0,0);


	return 0;
}