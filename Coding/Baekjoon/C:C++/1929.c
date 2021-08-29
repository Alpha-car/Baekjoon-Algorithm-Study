#include <stdio.h>
#include <math.h>

void prime_discrimination(int num)
{
	int i, cnt=0;
	double sq;
	int SQ;
	sq = sqrt((double)num);
	SQ = (int)sq/1;

	for(i=2;i<=SQ;++i){
		if((int)num%i==0)
			cnt++;
	}

	return;
}


int main(void)
{
	int M, N, i;

	scanf("%d%d", &M, &N);
	prime_discrimination(i);

	return 0;
}