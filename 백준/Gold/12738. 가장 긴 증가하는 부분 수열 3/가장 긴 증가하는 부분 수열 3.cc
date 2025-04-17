#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int num;
	int idx;
};

int N;
vector<Node> v;

void search_bi(int now, int idx) {

	int left = 1;
	int right = v.size() - 1;
	int mid = (left + right) / 2;

	while (left < right) {
		if (v[mid].num < now) left = mid + 1;
		if (v[mid].num > now) right = mid;
		if (v[mid].num == now) break;
		mid = (left + right) / 2;
	}
	v[mid] = { now, idx };
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	v.push_back({ (int)-1e9 - 1, 0 });
	int end = 0;

	for (int i = 1; i <= N; i++) {
		int now;
		cin >> now;

		if (v[end].num > now) search_bi(now, i);
		if (v[end].num < now) {
			v.push_back({ now, i });
			end++;
		}
	}

	cout << v.size() - 1 << '\n';

	return 0;
}