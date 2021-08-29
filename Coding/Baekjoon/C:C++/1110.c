#include <stdio.h>

int main(void) 
{
	int M, N;
	int i;
	int b1, b2, tmp;

	scanf("%d", &N);
	M=N;
	i=0;
	b1 = N % 10;
	b2 = N / 10;
	tmp = (b2 + b1) % 10;
	N = 10*b1 + tmp;
	++i;
	for(i=1;!(M==N);++i) {
		b1 = N % 10;
		b2 = N / 10;
		tmp = (b2 + b1) % 10;
		N = 10*b1 + tmp;
	}
	printf("%d\n", i);

	return 0;
}