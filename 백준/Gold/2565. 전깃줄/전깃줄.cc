#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[502] = { 0, };
vector<int> v;
int idx = 0;

void search_bi(int a) {

	int l = 0;
	int r = idx;
	int mid = (l + r) / 2;

	while (l < r) {
		mid = (l + r) / 2;
		if (v[mid] > a) r = mid;
		else if (v[mid] < a) l = mid + 1;
		else break;
	}

	v[l] = a;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	int M = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
		M = max(M, a);
	}

	v.push_back(0);
	for (int i = 1; i <= M; i++) {
		int a = arr[i];
		if (a == 0) continue;
		if (v[idx] > a) search_bi(a);
		else if (v[idx] < a) {
			v.push_back(a);
			idx++;
		}
	}

	cout << N - idx;

	return 0;
}