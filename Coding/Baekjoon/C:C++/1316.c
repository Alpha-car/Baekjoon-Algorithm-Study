#include <stdio.h>

int group_discrimination(char a[])
{
	int i;
	int cnt[123] = {0, };				// 'z' == 122 이므로
	int tmp, dcm;

	tmp = a[0];
	cnt[tmp]++;
	for(i=1;a[i]!='\0';++i){
		if(a[i-1]!=a[i]){
			tmp = a[i];
			cnt[tmp]++;
		}
	}
	dcm = 0;
	for(i=0;i<123;++i){
		if(cnt[i]!=0 && cnt[i]!=1)
			dcm++;
	}
	if(dcm==0)
		return 1;
	return 0;
}
/*
ex) 0011221
첫째 숫자는 cnt[0]에 카운트
전의 숫자와 지금 나오는 숫자가 같다면 카운트 안하고
전의 숫자와 지금 나오는 숫자가 다르다면 카운트 하고
*/
int main(void)
{
	int N;
	char a[101];
	int result = 0;
	int i;

	scanf("%d", &N);
	for(i=0;i<N;++i){
		scanf("%s", a);
		if(group_discrimination(a)!=0)
			result++;
	}
	printf("%d\n", result);
	return 0;
}