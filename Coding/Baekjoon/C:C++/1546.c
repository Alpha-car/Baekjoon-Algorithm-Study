#include <stdio.h>

int main(void)
{
	int n;
	double a;
	double M = 0.0;
	int i;
	double sum = 0.0;
	double avrg;

	scanf("%d", &n);
	for(i=0;i<n;++i) {
		scanf("%lf", &a);
		if(M<a)
			M = a;
		sum = sum + a;
	}
	avrg = sum/(M*n) * 100;
	printf("%f", avrg);

	return 0;
}

/* 40 80 60
   50 100 75 -> 75
   (40+80+60)/(3*80)*100 -> 75
*/