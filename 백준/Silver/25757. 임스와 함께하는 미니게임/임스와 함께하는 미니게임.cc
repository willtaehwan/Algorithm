#include <iostream>
#include<unordered_set>
using namespace std;

unordered_set<string> name;

int N;
char g;

int game(char g) {
	int num = 0;
	if (g == 'Y') num = 1;
	if (g == 'F') num = 2;
	if (g == 'O') num = 3;

	return num;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> g;
	for (int i = 0; i < N; i++) {
		string now;
		cin >> now;
		name.insert(now);
	}

	cout << name.size() / game(g);

	return 0;
}