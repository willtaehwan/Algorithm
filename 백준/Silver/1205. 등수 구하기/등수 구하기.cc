#include <iostream>
using namespace std;

int main(){
	int N,s,P,p,n,r=1;
	cin>>N>>s>>P;
	for (int i = 0; i < N; i++) {
		cin >> n;
		if (n > s)r++;
	}
	if(N==P&&n>=s)r=-1;
	cout<<r;
}