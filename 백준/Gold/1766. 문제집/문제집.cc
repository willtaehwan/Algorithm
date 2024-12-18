#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

vector<int> v[32002];
int arr[32002] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		arr[b]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int now = pq.top(); pq.pop();

		cout << now << " ";

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			arr[next]--;
			if (arr[next] == 0) pq.push(next);
		}

	}

	return 0;
}