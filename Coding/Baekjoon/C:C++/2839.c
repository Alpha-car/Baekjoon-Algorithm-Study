#include <stdio.h>

int main(void)
{
	int N;
	int cnt;
	int i;
	int mul5, mul3;

	scanf("%d",&N);
//	mul5 = N/5;
//	3으로 나눠보고
//	안되면 N/5에서 1 까기
	if(N != 4 && N != 7) {
		mul5 = N/5;
		i = 0;
		while(1) {
			if((N - 5*mul5)%3==0)
				break;
			else {
				mul5 = mul5 - 1;
				++i;
			}
		}
		mul3 = (N - 5*mul5)/3;
		cnt = mul5 + mul3;
	}
	else
		cnt = -1;
	printf("%d\n", cnt);

	return 0;
}


/*
18 진입
18 - 5 => 13 % 3
13 - 5 => 8 % 3
8 - 5 => 3 % 3

N 15
mul5 3
(15 - 5*3) % 3 ==0 ...i=0
...mul5 3, mul3 0

N 16
mul5 3
(16 - 5*3) % 3 !=0
3 -> 2
(16 - 5*2) % 3 ==0 ...i=1
...mul5 2, mul3 2

N 17
mul5 3
(17 - 5*3) % 3 !=0
3 -> 2
(17 - 5*2) % 3 !=0
2 -> 1
(17 - 5*1) % 3 ==0 ...i==2
...mul5 1, mul3 4

N 18
mul5 3
(18 - 5*3) % 3 ==0 ...i==0
...mul5 3, mul3 1

N 19
mul5 3
(19 - 5*3) % 3 !=0
3 -> 2
(19 - 5*2) % 3 ==0 ...i==1
...mul5 2, mul3 3
*/