#include <stdio.h>

int factorial(int x)
{
	if(x == 1) return 1;
	return x * factorial(x-1);
}

int main(void)
{
	int N, K;
	int Com;

	scanf("%d%d", &N, &K);
	Com = factorial(N) / (factorial(K) * factorial(N-K));
	printf("%d\n", Com);

	return 0;
}