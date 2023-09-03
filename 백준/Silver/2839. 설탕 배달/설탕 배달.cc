#include <iostream>
using namespace std;

int main() {
	
	int N;

	cin >> N;
	int result = -1;
	
	if (N % 5 == 0) {
		result = N / 5;
	}
	else {
		for (int i = (N / 5); i >= 0; i--) {
			int check = N - i * 5;
			
			if (check % 3 == 0) {
				result = i + check / 3;
				break;
			}
		}
	}
	
	
	
	

	cout << result;
	return 0;
}