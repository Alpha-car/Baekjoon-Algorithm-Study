#include <stdio.h>

int main(void)
{
	int a[2001]={0, };
	int N;
	int i;
	int input, now;

	scanf("%d", &N);
	for(i=0;i<N;++i) {
		scanf("%d", &input);
		now = input + 1000;
		a[now]++;
	}
	for(i=0;i<2001;++i) {
		if(a[i]!=0) {
			printf("%d ", i-1000);
			a[i] = 0;
		}
	}

	return 0;
}