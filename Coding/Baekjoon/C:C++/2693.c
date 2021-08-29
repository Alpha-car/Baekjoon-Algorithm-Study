#include <stdio.h>

int main(void)
{
	int T, A[10]={0, };
	int tmp;
	int cnt[1001] = {0, };
	int i, j;

	scanf("%d", &T);
	for(i=0;i<T;++i){
		for(j=0;j<10;++j){
			scanf("%d", &A[j]);
			cnt[A[j]]++;
		}	

		tmp = 0;
		for(j=1000;tmp<3;--j){

			if(cnt[j]>0){ 
//				printf("tmp: %d\n", tmp);
				tmp++;
			}
		}
		
	printf("%d\n", j+1);
	for(j=1;j<=1000;++j)
			cnt[j] = 0;
	}

	return 0;
}