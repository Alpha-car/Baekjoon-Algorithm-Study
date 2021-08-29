#include <stdio.h>

int main(void)
{
	int a[10001] = {0};
	int N;
	int input, tmp;
	int i, j;

	scanf("%d", &N);
	for(i=0;i<N;++i) {
		scanf("%d", &input);
		a[input]++;
	}
	for(i=1;i<=10000 && !(a[10001]==0);++i) {
		tmp = a[i];
		for(j=0;j<tmp;++j) {
			printf("%d\n", i);
			a[i]--;
		}
	}
	return 0;
}