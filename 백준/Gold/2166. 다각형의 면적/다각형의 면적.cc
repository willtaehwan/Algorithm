#include <iostream>

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	long double result = 0.0;
	
	long long o_x, o_y;
	cin >> o_x >> o_y;
	
	long long t_x, t_y;
	cin >> t_x >> t_y;

	for (int i = 0; i < N-2; i++) {
		long long x, y;
		cin >> x >> y;
		result += (o_x * t_y + t_x * y + x * o_y - t_x * o_y - x * t_y - o_x * y) * 0.5;
		t_x = x;
		t_y = y;
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(result);

	return 0;
}