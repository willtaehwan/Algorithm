#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> va;
vector<int> vb;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		va.push_back(a);
		vb.push_back(b);
	}

	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
		
	cout << va[N / 2] << " " << vb[N / 2];

	return 0;
}