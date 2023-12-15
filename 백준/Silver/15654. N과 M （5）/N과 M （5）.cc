#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

struct Node {
	int num;
	bool check;
};

Node arr[8];
vector<int> v;
int path[8];
int cnt = 0;
void dfs(int now) {

	if (now >= M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (arr[i].check) continue;

		path[cnt++] = arr[i].num;
		arr[i].check = true;
		dfs(now + 1);
		path[--cnt] = 0;
		arr[i].check = false;
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

	for (int i = 0; i < N; i++) {
		arr[i].num = v[i];
		arr[i].check = false;
	}

	dfs(0);


	return 0;
}