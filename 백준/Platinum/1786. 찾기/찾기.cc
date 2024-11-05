#include <iostream>
#include <vector>
#include <string>
#define MAX 1100002
using namespace std;

string T, P;
int ml, mi = 0;
int arr[MAX] = { 0, };
vector<int> v;

void k_search(int now, int prev) {
	if (P[prev] == P[now - 1]) arr[now] = prev + 1;
	else if(prev != 0) k_search(now, arr[prev]);
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	getline(cin, T);
	getline(cin, P);

	for (int i = 2; i <= P.size(); i++) k_search(i, arr[i - 1]);

	int cnt = 0;
	for (int i = 0; i < T.size(); i++) {
		if (T[i] == P[cnt]) cnt++;
		else {
			if (T[i] == P[arr[cnt]]) cnt = arr[cnt] + 1;
			else cnt = 0;
		}

		if (cnt == P.size()) {
			v.push_back(i - cnt + 2);
			cnt = arr[cnt];
		}
	}

	cout << v.size()<<'\n';
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";

	return 0;
}