#include <stdio.h>
#define MAX 101


int main(void)
{
	int A, B, C;
	int start, finish;
	int cnt[MAX] = {0, };
	int payment = 0;

	scanf("%d%d%d", &A, &B, &C);
	for(int i = 0; i<3; ++i){
		scanf("%d%d", &start, &finish);
		for(int j = start; j<finish; ++j){
			cnt[j]++;
		}
	}
	for(int i = 0; i<MAX; ++i){
		if(cnt[i] == 3){
			payment += 3*C;
		}
		else if(cnt[i] == 2){
			payment += 2*B;
		}
		else if(cnt[i] == 1){
			payment += 1*A;
		}
	}
	printf("%d\n", payment);

	return 0;
}