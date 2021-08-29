#include <stdio.h>

int main(void)
{
	char N[11];
	int i, j, tmp;

	scanf("%s", N);
	for(i=0;N[i+1]!='\0';++i){
		for(j=i;N[j]!='\0';++j){
			if(N[i]-'0' < N[j]-'0'){
				tmp = N[i];
				N[i] = N[j];
				N[j] = tmp;
			}
		}
	}
	printf("%s", N);
	return 0;
}