#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;
int path[8] = { 0, };
int visited[8] = { 0, };
int cnt = 0;

void dfs(int now) {

	if (now == M) {
		for (int i = 0; i < M; i++) {
			cout << path[i]<<" ";
			
		}
		cout << endl;
		return;
	}
	int temp = 0;
	for (int i = 0; i < v.size(); i++) {
		int next = v[i];
		if (visited[i] != 0) continue;
		if (temp == next) continue;
		temp = next;
		path[cnt++] = next;
		visited[i] = 1;
		dfs(now + 1);
		visited[i] = 0;
		path[--cnt] = 0;

	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a = 0;
		cin >> a;
		v.push_back(a);
	}
	
	sort(v.begin(), v.end());
	
	dfs(0);

	return 0;
}