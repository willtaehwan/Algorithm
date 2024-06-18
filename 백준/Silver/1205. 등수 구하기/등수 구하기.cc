#include <iostream>
int main(){
	int N,s,P,p,n,r=1;
	std::cin>>N>>s>>P;
	for(int i=0;i<N;i++){
		std::cin>>n;
		if(n>s)r++;
	}
	if(N==P&&n>=s)r=-1;
	std::cout<<r;
}