#include <iostream>

using namespace std;


int main() {

	int N;

	cin >> N;
	long long int g = 0;
	for (int i = 1; i <= N; i++) { 
		
		g += (N / i) * i;
		
	}

	cout << g;
	return 0;
}