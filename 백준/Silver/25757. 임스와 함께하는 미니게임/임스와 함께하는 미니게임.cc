#include <iostream>
#include<unordered_set>
using namespace std;

unordered_set<string> name;

int N;
char g;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num = 1;
	cin >> N >> g;
	for (int i = 0; i < N; i++) {
		string now;
		cin >> now;
		name.insert(now);
	}

	if (g == 'F') num = 2;
	if (g == 'O') num = 3;

	cout << name.size() / num;

	return 0;
}