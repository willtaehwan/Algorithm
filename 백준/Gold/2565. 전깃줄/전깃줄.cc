#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[102] = { 0, };

vector<pair<int, int>> v;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	int m = 0;
	for (int i = 0; i < N; i++) {
		arr[i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i].second <= v[j].second) continue;
			arr[i] = max(arr[i], arr[j] + 1);
		}
		m = max(m, arr[i]);
	}

	cout << N - m;

	return 0;
}