#include <iostream>

using namespace std;

int h, m, s, t;
int result = 0;

int main() {

	cin >> h >> m >> s;
	cin >> t;

	result = h * 3600 + m * 60 + s;
	result = (result + t) % 86400;

	cout << result / 3600 << " ";
	result %= 3600;
	cout << result / 60 << " ";
	result %= 60;
	cout << result;


	return 0;
}