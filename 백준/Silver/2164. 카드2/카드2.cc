#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int N;

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) q.push(i);
	
	while (q.size() != 1) {
		q.pop();
		int a = q.front(); 
		q.pop();
		q.push(a);
	}

	cout << q.front();

	return 0;
}