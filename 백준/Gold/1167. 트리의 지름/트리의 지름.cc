#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int ed;
	int cost;
};

int V;

vector<Edge> v[100001];


int dist[100001] = { 0, };

int dfs(int now, int cost) {

	int max_di = 0;
	int sec_di = 0;
	dist[now] = cost;
	//cout << now << "=======\n";
	for (int i = 0; i < v[now].size(); i++) {
		Edge next = v[now][i];
		if (dist[next.ed] != -1) continue;

		int di = dfs(next.ed, next.cost);
		if (max_di < di) {
			sec_di = max_di;
			max_di = di;
		}
		else if (sec_di < di) sec_di = di;
	}
	//cout << now << " : " << max_di << "  ,  " << sec_di << "   @@@@@@@\n";
	dist[now] = max_di + sec_di;

	return max_di + cost;

}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> V;
	for (int i = 0; i < V; i++) {
		int st;
		cin >> st;
		while (1) {
			int ed, cost;
			cin >> ed;
			if (ed == -1) break;
			cin >> cost;
			v[st].push_back({ ed, cost });
		}
	}

	for (int i = 1; i <= V; i++) dist[i] = -1;

	dfs(1, 0);
	int result = 0;
	for (int i = 1; i <= V; i++) {
		if (result < dist[i]) result = dist[i];
	}

	cout << result;

	return 0;
}