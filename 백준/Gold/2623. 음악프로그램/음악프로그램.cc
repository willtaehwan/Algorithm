#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;

int arr[1002];
bool check[1002];
vector<int> v[1002];
queue<int> q;
queue<int> result;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int cnt, first;
		cin >> cnt >> first;

		for (int j = 1; j < cnt; j++) {
			int next;
			cin >> next;
			v[first].push_back(next);
			arr[next]++;
			first = next;
		}

	}

	//for (int i = 0; i <= N; i++) cout << arr[i] << " ";

	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();

		result.push(now);
		check[now] = true;

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			arr[next]--;
			if (arr[next] == 0) q.push(next);
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (arr[i]) {
			cout << 0;
			return 0;
		}
	}


	
	while (!result.empty()) {
		int now = result.front(); result.pop();
		cout << now << "\n";
	}
	


	return 0;
}