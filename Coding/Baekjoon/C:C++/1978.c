#include <stdio.h>

int main(void)
{
	int N;
	int a, i, j, k;
	int x;

	scanf("%d", &N);
	i=0; k=0;
	while(i<N) {
		scanf("%d", &a);
		j=1;
		x=0;
		if(a!=2) {
			while(j<a-1) { 
				if(a%(a-j)!=0) {x = 1; ++j;}
				else {x = 0; break;}
			}
		}
		else x = 1;
		if(x == 1) {++k; ++i;}
		else {++i;}
	}
	printf("%d\n", k);
	return 0;
}