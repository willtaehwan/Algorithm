#include <iostream>
#define MAX 1000002
using namespace std;

int N;
string s;
int arr[MAX] = { 0, };

void k_search(int now, int prev) {
	if (s[prev] == s[now - 1]) arr[now] = prev + 1;
	else if (prev != 0) k_search(now, arr[prev]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> s;
	for (int i = 2; i <= s.size(); i++) k_search(i, arr[i - 1]);
	cout << N - arr[s.size()];
	return 0;
}