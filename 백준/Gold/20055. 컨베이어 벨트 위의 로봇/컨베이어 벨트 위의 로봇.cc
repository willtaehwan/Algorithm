#include <iostream>

using namespace std;

int N, K;

struct status {
	bool robot;
	int Durability;
};

status belt[202];

int inPoint = 0;
int outPoint = 0;
int rustZone = 0;

void rM2(int now) {

	if (belt[now].robot) {
		int next = now + 1;
		if (next == N * 2) next = 0;
		if (belt[next].robot) return;
		if (belt[next].Durability == 0) return;

		belt[now].robot = false;
		belt[next].robot = true;
		belt[next].Durability--;
		if (belt[next].Durability == 0) rustZone++;
		if (next == outPoint) belt[next].robot = false;
	}

}

void robotMove() {

	if (inPoint > outPoint) {
		for (int i = outPoint; i >= 0; i--) rM2(i);
		for (int i = N * 2 - 1; i >= inPoint; i--) rM2(i);
	}
	else {
		for (int i = outPoint; i >= inPoint; i--) rM2(i);
	}

	return;
}

void inputRobot(int cp) {

	if (belt[cp].Durability > 0) {
		belt[cp].robot = true;
		belt[cp].Durability--;
		if (belt[cp].Durability == 0) rustZone++;
	}

	return;
}

void init() {
	cin >> N >> K;
	outPoint = N-1;
	for (int i = 0; i < N * 2; i++) {
		cin >> belt[i].Durability;
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	int cnt = 0;
	while (1) {
		cnt++;
		inPoint--;
		outPoint--;
		if (inPoint == -1) inPoint = N * 2 - 1;
		if (outPoint == -1) outPoint = N * 2 - 1;
		belt[outPoint].robot = false;
		robotMove();

		inputRobot(inPoint);

		if (rustZone >= K) break;

		/*for (int i = 0; i < N * 2; i++) {
			cout << belt[i].Durability << "/";
			if (belt[i].robot) cout << "Y ";
			else cout << "N ";
		}
		cout << " in : " << inPoint << " /  out : " << outPoint << " ";
		cout << endl;*/
	}
	
	
	/*for (int i = 0; i < N * 2; i++) {
		cout << belt[i].Durability << " ";
	}
	cout << endl;*/

	cout << cnt;


	return 0;
}