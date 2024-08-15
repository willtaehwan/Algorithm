#include <iostream>
#include <vector>
using namespace std;

int N;

vector<int> v;

void search_bi(int now) {
	
	int left = 1;
	int right = v.size() - 1;
	int mid = (left + right) / 2;

	while (left < right) {
		if (v[mid] < now) left = mid + 1;
		if (v[mid] > now) right = mid;
		if (v[mid] == now) break;

		mid = (left + right) / 2;
	}
	
	v[mid] = now;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	v.push_back(0);
	int end = 0;
	
	for (int i = 0; i < N; i++){
		int now;
		cin >> now;

		if (v[end] > now) search_bi(now);
		
		if (v[end] < now) {
			v.push_back(now);
			end++;
		}
	}

	cout << v.size() - 1;

	return 0;
}