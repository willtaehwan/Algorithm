#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int x;
	int y;

	bool operator<(Node r) const {
		if (x < r.x) return true;
		return false;
	}
};

int N;
vector<Node> v;

int cal(Node a, Node b) {
	int x = b.x - a.x;
	int y = b.y - a.y;
	return x * x + y * y;
}


int min_dist(int st, int ed) {

	int n = ed - st + 1;
	if (n == 2) return cal(v[st], v[ed]);
	if (n == 3) {
		return min({ cal(v[st], v[ed]), cal(v[st], v[st + 1]), cal(v[st + 1], v[ed]) });
	}

	int mid = (st + ed) / 2;
	int md = min(min_dist(st, mid), min_dist(mid + 1, ed));

	vector<Node> v2;
	//v2.reserve(n);
	int line = (v[mid].x + v[mid + 1].x) / 2;

	for (int i = st; i <= ed; i++) {
		int t = line - v[i].x;
		if (t * t < md) v2.push_back({ v[i].y, v[i].x });
	}

	sort(v2.begin(), v2.end());

	for (int i = 0; i < v2.size(); i++) {
		for (int j = i + 1; j < v2.size(); j++) {
			int t = v2[i].x - v2[j].x;
			if (t * t >= md) break;
			md = min(md, cal(v2[i], v2[j]));
		}
	}

	return md;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());

	cout << min_dist(0, N-1);


	return 0;
}