#include <iostream>
#include <vector>
using namespace std;

struct Node {
	bool checked;
	int a;
	int idx;
};

int M, Q;

int ed[200002] = { 0, };
bool visited[200002] = { 0, };
int path[200002] = { 0, };

vector<int> v[200002];
bool cycle_v[200002];

Node nd[200002];

int vcnt = 0;
int result = 0;
void search_result(int n, int x) {

	int nl = nd[x].a;
	int ni = nd[x].idx;

	if (!cycle_v[nl]) {
		if (ni + n < v[nl].size()) {
			result = v[nl][ni + n];
			return;
		}
		else {
			int next_n = n - (v[nl].size() - ni);
			search_result(next_n, ed[v[nl][v[nl].size() - 1]]);
		}
	}
	else {
		int ri = (n + ni) % v[nl].size();
		result = v[nl][ri];
		return;
	}

	return;
}

void dfs(int now, int cnt) {

	if (nd[now].checked) {
		if (cnt == 0) return;
		int ncnt = 0;
		cycle_v[vcnt] = false;
		for (int i = 0; i < cnt; i++) {
			if (path[i] == now) {
				ncnt = 0;
				if(v[vcnt].size()) vcnt += 1;
				cycle_v[vcnt] = true;
			}
			v[vcnt].push_back(path[i]);
			nd[path[i]] = { true, vcnt, ncnt++ };
		}

		vcnt++;
		return;
	}
	nd[now].checked = true;
	path[cnt] = now;
	dfs(ed[now], cnt + 1);

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M;

	for (int i = 1; i <= M; i++) {
		cin >> ed[i];
		nd[i].checked = false;
	}

	for (int i = 1; i <= M; i++) {
		dfs(i, 0);
	}
	/*cout << vcnt << "\n";
	for (int i = 0; i < vcnt; i++) {
		cout << cycle_v[i] << " _ ";
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << '\n';
	}*/

	//for (int i = 1; i <= M; i++) cout << nd[i].a << " " << nd[i].idx<<'\n';



	cin >> Q;
	for (int i = 0; i < Q; i++) {
		int n, x;
		cin >> n >> x;
		search_result(n, x);
		cout << result << '\n';
	}

	return 0;
}