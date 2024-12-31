#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

bool check_lr(int idx, int num1_idx) {
	bool flag = false;
	if (idx + 1 >= N) flag = false;
	else if (v[idx] == v[idx + 1] && num1_idx != idx + 1) return true;

	if (idx - 1 < 0) flag = false;
	else if (v[idx] == v[idx - 1] && num1_idx != idx - 1) return true;

	return flag;
}

bool binary_search(int now, int idx) {

	for (int i = 0; i < N; i++) {
		if (i == idx) continue;
		int target = now - v[i];
		//cout <<"   TARGET = " << target << " (" << v[i]<< ")\n";
		int left = i + 1;
		int right = v.size() - 1;
		if (target < v[i]) break;

		while (left <= right) {
			int mid = (left + right) / 2;
			//cout << left << " " << right << " = " << v[mid]<< "\n";
			if (v[mid] == target) {
				if (mid == idx) {
					if (!check_lr(mid, i)) break;
				}
				return true;
			}
			if (left == right) break;

			if (v[mid] > target) right = mid;
			if (v[mid] < target) left = mid + 1;
		}
	}

	return false;
}



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
	for (int i = 0; i < v.size(); i++) {
		//cout << "ID = " << v[i] << "\n";
		if (binary_search(v[i], i)) {
			//cout << "OK\n";
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}