#include <stdio.h>

int prime_determinent(int x)
{
	int i;
	int cnt = 0;
	for(i=1;i<x;++i) {
		if(x%i==0)
			cnt++;
	}
	if(cnt==0)
		return 1;
	return 0;
}

int main(void)
{
	int T, n;

	scanf("%d", &T);
	

}