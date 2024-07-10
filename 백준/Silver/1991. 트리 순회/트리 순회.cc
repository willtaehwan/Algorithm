#include <iostream>

using namespace std;

struct Tree {
	char left;
	char right;
};

int N;

Tree Node[26];

void preorder(int now) {
	cout << char('A' + now);
	if (Node[now].left) preorder(Node[now].left - 'A');
	if (Node[now].right) preorder(Node[now].right - 'A');
}

void inorder(int now) {
	if (Node[now].left) inorder(Node[now].left - 'A');
	cout << char('A' + now);
	if (Node[now].right) inorder(Node[now].right - 'A');
}

void postorder(int now) {
	if (Node[now].left) postorder(Node[now].left - 'A');
	if (Node[now].right) postorder(Node[now].right - 'A');
	cout << char('A' + now);
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		char root, l, r;
		cin >> root >> l >> r;
		if (l != '.') Node[root - 'A'].left = l;
		if (r != '.') Node[root - 'A'].right = r;
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);

	return 0;
}