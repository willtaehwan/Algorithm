#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int l = 0;
		int r = N - 1;

		while (l < r) {
			int res = v[l] + v[r];
			if (v[i] < res) r--;
			else if (v[i] > res) l++;
			else {
				if (l != i && r != i) {
					cnt++;
					break;
				}
				else if (l == i) l++;
				else if (r == i) r--;
			}
		}
	}
	cout << cnt;
	
	return 0;
}