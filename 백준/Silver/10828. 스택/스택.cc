#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int N;

void push() {
	int num;
	cin >> num;

	v.push_back(num);
}
void pop() {
	if (v.size() == 0) {
		cout << -1<<'\n';
	}
	else {
		cout << v[v.size() - 1]<<'\n';
		v.pop_back();
	}
	

}
void size() {
	cout << v.size()<<'\n';
}
void empty() {
	if (v.empty()) cout << 1<<'\n';
	else cout << 0<<'\n';
}
void top() {
	
	if (v.size() == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << v[v.size() - 1] << '\n';
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		if (row == "push") push();
		else if (row == "pop") pop();
		else if (row == "size") size();
		else if (row == "empty") empty();
		else if (row == "top") top();
	}


	return 0;
}