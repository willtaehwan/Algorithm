#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

vector<pair<int,int>> v; 


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int st, end;
		cin >> st >> end;
		v.push_back({ end,st });
	}

	sort(v.begin(), v.end());


	int time = v[0].first;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (time <= v[i].second) {
			cnt++;
			time = v[i].first;
		}
	}
	
	cout << cnt;

	return 0;
}