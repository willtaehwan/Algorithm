#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int price;
	int date;

	bool operator<(Node right) const {
		if (price < right.price) return false;
		if (price > right.price) return true;

		return false;
	}

};

vector<Node> map;

int N;
long long int sum = 0;

void init() {
	N = 0;
	sum = 0;
	map.clear();
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int price;
		cin >> price;
		map.push_back({ price, i });
	}

	sort(map.begin(), map.end());
	/*for (int i = 0; i < N; i++) {
		cout << map[i].date << " " << map[i].price << endl;
	}*/

}

void solution() {

	for (int i = 0; i < N; i++) {
		if (map[i].price == -1) continue;
		else {

			for (int j = i + 1; j < N; j++) {
				if (map[j].date < map[i].date && map[j].price >= 0) {

					sum += map[i].price - map[j].price;
					map[j].price = -1;
				}
			}

		}
	}

}

int main() {

	int T;

	cin >> T;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int tc = 1; tc <= T; tc++) {

		init();
		input();
		solution();

		cout << sum << endl;
	}

	return 0;
}