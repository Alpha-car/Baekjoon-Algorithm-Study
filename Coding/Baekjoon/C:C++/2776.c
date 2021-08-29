#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;
	if(num1 < num2) return -1;
	if(num1 > num2) return 1;
	return 0;
}

int search_in_N(int a, int N, int *n)
{
	int i;
	int low, high, mid;
	low = 0;
	high = N;
	while(low<=high){
		mid = (low+high)/2;
		if(n[mid] == a) return 1;
		else if(n[mid] > a)
			high = mid - 1;
		else if(n[mid] < a)
			low = mid + 1;
	}
	return 0;
}

int main(void)
{
	int T, N, M;
	int i, j;

	scanf("%d", &T);
	for(i=0;i<T;++i){
		scanf("%d", &N);
		int n[N];
		for(j=0;j<N;++j){
			scanf("%d", &n[j]);
		}
		qsort(n, sizeof(n)/sizeof(int), sizeof(int), compare);

		scanf("%d", &M);
		int m[M];
		for(j=0;j<M;++j){
			scanf("%d", &m[j]);
		}

		for(j=0;j<M;++j){
			printf("%d\n", search_in_N(m[j], N, n));
		}
	}

	return 0;
}