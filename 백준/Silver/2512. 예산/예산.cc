#include <iostream>

using namespace std;

struct Node {
	int budget;
	bool check;
};

int N, M;
Node h[10001];
int tot_budget;
int max_num;

void divide(int now, int rem) {
	//cout << now << " / " << rem << " = " << now/rem<<'\n';
	int di_cash = now / rem;
	int remain = now % rem;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (h[i].check) continue;

		if (h[i].budget <= di_cash) {
			remain += di_cash - h[i].budget;
			h[i].budget = 0;
			h[i].check = true;
		}
		else {
			cnt++;
			h[i].budget -= di_cash;
		}
	}
	max_num += di_cash;
	//cout << "   " << remain << '\n';
	if (remain / cnt > 0) divide(remain, cnt);

}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> h[i].budget;
		tot_budget += h[i].budget;
		if (max_num < h[i].budget) max_num = h[i].budget;
	}

	cin >> M;

	if (tot_budget > M){
		max_num = 0;
		divide(M, N);
	}
	cout << max_num;

	return 0;
}