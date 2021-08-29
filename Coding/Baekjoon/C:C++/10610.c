#include <stdio.h>

int ten(char a[])
{
	int i;
	int cnt = 0;
	for(i=0;a[i]!='\0';++i) {
		if(a[i]-'0'==0)
			cnt++;
	}
	if(cnt!=0)
		return 1;
	return 0;
}

int main(void)
{
	char a[100001];
	int cstr[10] = {0, };
	int tmp, sum;
	int i, j;
	sum = 0;

	scanf("%s", a);
	for(i=0;a[i]!='\0';++i) {
		tmp = a[i] - '0';
		sum = sum + tmp;
	}
	if(sum%3==0 && ten(a)==1) {
		for(i=0;a[i]!='\0';++i) {
			tmp = a[i] - '0';
			for(j=0;j<10;++j) {
				if(j==tmp)
					cstr[j] = cstr[j] + 1;
			}
		}
		for(i=9;i>=0;--i) {
			for(j=0;j<cstr[i];++j) {
				printf("%d", i);
			}
		}
		printf("\n");
	}
	else
		printf("%d\n", -1);


	return 0;
}

/*
30의 배수 만들기
3의 배수이고, 10의 배수이면 됨
3의 배수 => 자리수 다 더해서 3으로 나눌 때 나머지 0
10의 배수 => 맨 끝자리 0
*/