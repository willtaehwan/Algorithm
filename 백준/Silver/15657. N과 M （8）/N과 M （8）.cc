#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;
int cnt = 0;
int path[8] = { 0, };

void dfs(int now, int prev) {

	if (now >= M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		int next = v[i];
		if (prev > next) continue;

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
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	dfs(0,0);


	return 0;
}