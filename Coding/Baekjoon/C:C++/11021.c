#include <stdio.h>
 
int main(void) 
{
	int M, N;
	int i, j, k;
	int X, Y, Z;
	scanf("%d", &N);

	i=0;
	M=N;
	while(1) {
		if(0<=N && N<10) {
			N = 10*N + N;
		}
		else if(10<=N && N<=99) {
			for(j=0;!(0<=X && X<10);++j) {
				X = N - 10*j;
			}
			Y = j + X;
			for(k=0;!(0<=Z && Z<10);++k) {
				Z = Y - 10*k;
			}
			N = 10*X + Z;
		}
		++i;
		if(M==N) break;
	}
	printf("%d\n", i);

	return 0;
}