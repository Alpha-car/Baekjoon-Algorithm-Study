#include <stdio.h>
#include <math.h>

int main(void)
{
	int N, cnt;
	int arr[50] = {0, };
	int i, j;
	int tmp;

	scanf("%d", &cnt);
	for(i=0;i<cnt;++i) {
		scanf("%d", &arr[i]);
	}
	for(i=0;i<cnt-1;++i) {
		for(j=i+1;j<cnt;++j) {
			if(arr[i]>arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	if(cnt%2==1) {
		N = pow(arr[cnt/2], 2);
		tmp = 0;
		for(i=0;cnt/2+i!=cnt;++i) {
			if(arr[cnt/2-i]*arr[cnt/2+i]!=N)
				tmp++;
		}
	}
	else {
		N = arr[cnt/2-1] * arr[cnt/2];
		tmp = 0;
		for(i=0;cnt/2+i!=cnt;++i) {
			if(arr[cnt/2-1-i]*arr[cnt/2+i]!=N)
				tmp++;
		}
	}
	if(tmp==0) {
		printf("%d\n", N);
	}
	return 0;
}

100


 2 3 4 6  