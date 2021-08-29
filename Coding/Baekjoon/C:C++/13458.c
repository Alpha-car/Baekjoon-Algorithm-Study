#include <stdio.h>

#define MUL_NUM a[i]/C
typedef long long LL;

int a[1000001];

int main(void)
{
	int N, B, C;
	LL cnt;
	int i;

	scanf("%d", &N);
	for(i=0;i<N;++i)
		scanf("%d", &a[i]);
	scanf("%d%d", &B, &C);

	cnt = N;				//총 감독관은 무조건 N명
	for(i=0;i<N;++i){
		a[i] -= B;
	}

	for(i=0;i<N;++i){
		if(a[i]>0){
			if(a[i]%C==0)
				cnt += MUL_NUM;
			else
				cnt += MUL_NUM+1;
		}
	}
	printf("%lld\n", cnt);
	return 0;
}


/*
3 4 5
1 2 3
0 1 1		몫
1 0 1		나머지
2*1 2*1 2*2
1 1 2
C의 배수 중 인자 값과 가장 가까운데 C가 더 큰 것에서 배수 넘버 카운트
나누어떨어지면 몫 그대로 cnt에 카운트
나누어떨어지지 않으면 몫+1값 cnt에 카운트
*/
