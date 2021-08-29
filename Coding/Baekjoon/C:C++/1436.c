#include <stdio.h>

int main(void)
{
	int N;
	int i = 0;
	int tmp = 0;
	int cnt = 0;
	int num;

	scanf("%d", &N);

	while(cnt!=N){
		++i;
		num = i;
		while(num!=0){
			if(num%10==6){
				num /= 10;
				tmp++;
			}
			else{
				num /=10;
				tmp = 0;
			}
			if(tmp==3){
				++cnt;
				break;
			}
		}
		tmp = 0;
	}
	printf("%d\n", i);
	return 0;
}