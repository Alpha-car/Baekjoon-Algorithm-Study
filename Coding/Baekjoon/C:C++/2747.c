#include <stdio.h>

int main(void)
{
	int a, b, tmp;
	int fib;
	int i;
	int n;

	a = 0; b = 1;
	scanf("%d", &n);
	for(i=0;i<n-1;++i) {
		tmp = b;
		b = a + b;
		a = tmp;
	}
	fib = b;
	printf("%d\n", fib);
	return 0;
}