#include <iostream>
#define MAX 5001
using namespace std;

string P;
int arr[MAX] = { 0, };
int max_length = 0;

void k_search(int now, int prev) {
	if (P[prev] == P[now - 1]) {
		arr[now] = prev + 1;
		max_length = max(max_length, arr[now]);
	}
	else if (prev != 0) k_search(now, arr[prev]);
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> P;
	while(P.size() > 1){
		for (int i = 0; i <= P.size(); i++) arr[i] = 0;
		for (int i = 2; i <= P.size(); i++) k_search(i, arr[i - 1]);

		P.erase(P.begin(), P.begin() + 1);
	}

	cout << max_length;

	return 0;
}