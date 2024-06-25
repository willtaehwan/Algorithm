#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main() {

	int a, b, c;
	cin >> a >> b >> c;
	
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);

	sort(v.begin(), v.end());

	for (int i = 0; i < 3; i++) {
		cout << v[i] << " ";
	}

	return 0;
}