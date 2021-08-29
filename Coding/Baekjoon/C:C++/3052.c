#include <stdio.h>

int main(void)
{
	int a[10];
	int i, j;
	int cnt1 = 0;
	int cnt2 = 0;

	for(i=0;i<10;++i) {
		scanf("%d", &a[i]);
		a[i] = a[i]%42;
	}
	for(i=0;i<42;++i) {
		for(j=0;j<10;++j) {
			if(i==a[j]) {
				cnt1 = cnt1 + 1;
			}
		}
		if(cnt1 != 0)
			cnt2 = cnt2 +1;
		cnt1 = 0;
	}
	printf("%d\n", cnt2);

	return 0;
}