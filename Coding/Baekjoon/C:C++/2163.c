#include <stdio.h>
/*
3 2

2 -> 1 ... 2 
3 -> 2
1 + 2*2

3 -> 2 ... 3
2 -> 1
2 + 1*3

4 3

4 -> 3 ... 4
3 -> 2
3 + 2*4

3 -> 2 ... 3
4 -> 3
2 + 3*3
*/

int main(void)
{
	int N, M;
	int cnt;

	scanf("%d%d", &N, &M);
	if((N-1)+N*(M-1) >= (M-1)+M*(N-1))
		printf("%d\n", (M-1)+M*(N-1));
	else
		printf("%d\n", (N-1)+N*(M-1));

	return 0;
}