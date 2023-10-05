#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int mapN[500001];
int mapM[500001];

int check(int A) {

	int left = 0;
	int right = N - 1;

	int leftcnt = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
	
		if (mapN[mid] >= A) {
			right = mid - 1;
			if (mapN[mid] == A) leftcnt = mid;
		}
		else {
			left = mid + 1;
		}
	}


	left = 0;
	right = N - 1;
	int rightcnt = -1;
	while (left <= right) {
		int mid = (left + right) / 2;

		if (mapN[mid] > A) {
			right = mid - 1;
			
		}
		else {
			left = mid + 1;
			if (mapN[mid] == A) rightcnt = mid;
		}
	}
	int result = 0;
	if (rightcnt == -1 && leftcnt == -1) result = 0;
	else result = rightcnt - leftcnt + 1;

	return result;

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> mapN[i];
	}

	sort(mapN, mapN + N);

	/*for (int i = 0; i < N; i++) {
		cout << mapN[i] << " ";
	}
	cout << endl;*/

	cin >> M;
	for (int i = 0; i < M; i++) {
		int A;
		cin >> A;
		int result = check(A);
		cout << result << " ";
	}

	

	return 0;
}