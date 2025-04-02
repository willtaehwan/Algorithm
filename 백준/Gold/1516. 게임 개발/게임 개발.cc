#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int arr[502] = { 0, };
int ti[502] = { 0, };
int t[502] = { 0, };

vector<int> v[501];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		cin >> ti[i];

		while (1) {
			int a;
			cin >> a;
			if (a == -1) break;

			v[a].push_back(i);
			arr[i]++;
		}
		if (arr[i] == 0) {
			t[i] += ti[i];
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];

			arr[next]--;
			t[next] = max(t[next], t[now]);
			if (arr[next] == 0) {
				t[next] += ti[next];
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= N; i++) cout << t[i] << "\n";

	return 0;
}