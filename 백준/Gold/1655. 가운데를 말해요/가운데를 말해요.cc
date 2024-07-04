#include <iostream>
#include <queue>
using namespace std;

/*
최소힙 최대힙에 숫자를 번갈아가며 입력
최대힙 먼저 넣음
최대힙 front > 최소힙 front면 두 값 교체

*/

int N;
int cnt = 0;

priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int> max_heap;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (i % 2 == 0) max_heap.push(a);
		else min_heap.push(a);
		
		if (i == 0) {
			cout << a<<'\n';
			continue;
		}
		int min_temp = min_heap.top();
		int max_temp = max_heap.top();

		if (min_temp < max_temp) {
			min_heap.pop();
			min_heap.push(max_temp);
			max_heap.pop();
			max_heap.push(min_temp);
		}
		
		cout <<max_heap.top()<<'\n';
	}

	return 0;
}