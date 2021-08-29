#include <stdio.h>

int arr[20000001];

int main(void)
{
	int N, M;
	int x;
	int i;

	scanf("%d", &N);
	for(i=0;i<N;++i){
		scanf("%d", &x);
		arr[x+10000000] += 1;
	}
	scanf("%d", &M);
	for(i=0;i<M;++i){
		scanf("%d", &x);
		arr[x+10000000] += 2;
		if(arr[x+10000000]==3)
			printf("%d ", 1);
		else if(arr[x+10000000]==2)
			printf("%d ", 0);
	}
/*
       Mx  Mo(+2)				
Nx     0   2
No(+1) 1   3    

*/
	return 0;
}