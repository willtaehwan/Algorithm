#include <iostream>
#include <unordered_map>
using namespace std;

int T, N, M;

int A[1002] = { 0, };
int B[1002] = { 0, };

unordered_map<int, long long> mA;
unordered_map<int, long long> mB;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		A[i] = A[i - 1] + a;
	}

	cin >> M;
	for (int i = 1; i <= M; i++) {
		int b;
		cin >> b;
		B[i] = B[i - 1] + b;
	}

	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			mA[A[i] - A[j]]++;
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < i; j++) {
			mB[B[i] - B[j]]++;
		}
	}
	long long ans = 0;
	for (auto it : mA) {
		if(mB.find(T-it.first) != mB.end()) ans += it.second * mB[T - it.first];
	}
	cout << ans;


	return 0;
}