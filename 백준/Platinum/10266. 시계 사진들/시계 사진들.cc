#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v1;
vector<int> v2;
vector<int> c1;
vector<int> c2;

int arr[360002] = { 0, };

void k_search(int now, int prev) {
	if (c2[prev] == c2[now - 1]) arr[now] = prev + 1;
	else if (prev != 0) k_search(now, arr[prev]);
}


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a == 0) a = 360000;
		v1.push_back(a);
	}

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a == 0) a = 360000;
		v2.push_back(a);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	for (int i = 0; i < N - 1; i++) c1.push_back(v1[i + 1] - v1[i]);
	c1.push_back(360000 + v1[0] - v1[N - 1]);
	for (int i = 0; i < N - 1; i++) c2.push_back(v2[i + 1] - v2[i]);
	c2.push_back(360000 + v2[0] - v2[N - 1]);

	//for (int i = 0; i < N; i++) cout << c1[i] << " ";
	//for (int i = 0; i < N; i++) cout << c1[i] << " ";
	//cout << '\n';
	//for (int i = 0; i < N; i++) cout << c2[i] << " ";
	//cout << '\n';

	for (int i = 2; i <= N; i++) k_search(i, arr[i - 1]);

	//for (int i = 0; i <= N; i++) cout << arr[i] << " ";
	//cout << '\n';

	int cnt = 0;
	for (int i = 0; i < N * 2; i++) {
		if (c1[i % N] == c2[cnt]) cnt++;
		else {
			if (c1[i % N] == c2[arr[cnt]]) cnt = arr[cnt] + 1;
			else cnt = 0;
		}

		if (cnt == N) {
			cout << "possible";
			return 0;
		}
	}

	cout << "impossible";
	return 0;
}