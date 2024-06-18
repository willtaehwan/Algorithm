#include <stdio.h>
int main(){
	int N,s,P,p,n,r=1;
	scanf("%d %d %d",&N,&s,&P);
	for(int i=0;i<N;i++){
		scanf("%d",&n);
		if(n>s)r++;
	}
	if(N==P&&n>=s)r=-1;
	printf("%d",r);
}