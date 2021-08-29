#include <stdio.h>

int main(void)
{
	int N;
	int a;
	int h, i, j;
	int x;

	scanf("%d", &N);
	int tmp[N];
	for(i=0;i<N;++i) {
		scanf("%d", &tmp[i]);
	}
	int arg[N];
	for(i=0;i<N;++i) {
		arg[i] = 1000;
	}

	for(j=0;j<N;++j) {
		for(i=0;i<N;++i) {
			x=0;
			for(h=0;h<N;++h) {
				if(tmp[i]==arg[h]) x = x + 1;
			}
			if(x) ;
			else
				if(arg[j]>tmp[i])
					arg[j] = tmp[i];
		}
	}
	for(i=0;i<N;++i) {
		printf("%d\n", arg[i]);
	}
/*
	for(i=0;i<N;++i) {
		if(arg[0]>tmp[i])
			arg[0] = tmp[i];
	}
	for(i=0;i<N;++i) {
		if(arg[0]==tmp[i])
		if(arg[1]>tmp[i] && arg[0]<arg[1])
			arg[1] = tmp[i];
	}
	for(i=0;i<N;++i) {
		if(arg[2]>tmp[i] && arg[1]<arg[2])
			arg[2] = tmp[i];
	}
*/

	/*
	int arg[N]=tmp[N];
	for(i=0;arg[i]>arg[i+1];++i) {
		if(arg[i] > arg[i+1]) {
			arg[i] = tmp[i+1];
			arg[i+1] = tmp[i];
		}
	}
	for(i=0;i<N;++i) {
		printf("%d\n", arg[i]);
	}
*/




/*

tmp{5 3 4}
arg{5 3 4}

if(a0_5 > a0_3)
	a0_3 = t1_3
	a1_5 = t0_5

if(a1_5 > a2_4)

	int arg[N];
	arg[0] = -1000;
	for(j=0;j<N;++j) {
		for(i=0;i<N;++i) {
			scanf("%d", &a);
			if(arg[j] < a)
				arg[j] = a;
			printf("INNER = %d...%d\n", arg[j],j);
		}
		printf("OUTER = %d...%d\n\n", arg[j],j);
	}
*/

	return 0;
}

/*

5
2  2 5  5
3  3 5  5
4  4 5  5
1  1 5  5 

2 3 4 1 5

*/