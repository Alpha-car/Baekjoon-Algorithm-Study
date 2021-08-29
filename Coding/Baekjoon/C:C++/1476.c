#include <stdio.h>
#define F_E (year-E)%15
#define F_S (year-S)%28
#define F_M (year-M)%19


int main(void)
{
	int E, S, M;
	int year = 15*28*19;

	scanf("%d%d%d", &E, &S, &M);

	if(E==M && E!=S)
		year = E;
	else if(E==S && E!=M)
		year = S;
	else if(S==M && E!=S)
		year = M;
	else if(E!=S && S!=M && M!=E){
		if(E<S && E<M)
			year = E;
		else if(S<E && S<M)
			year = S;
		else if(M<E && M<S)
			year = M;
	}
	else if(E==S && S==M && M==E)
		year = E;


	while(!(F_E==0 && F_S==0 && F_M==0)){
//		printf("%d %d %d\n", E, S, M);
		if(F_E==0 && F_S==0 && F_M!=0)
			year += 15*28;
		else if(F_E==0 && F_S!=0 && F_M==0)
			year += 15*19;
		else if(F_E!=0 && F_S==0 && F_M==0)
				year += 19*28;
		else if(F_E==0 && F_S!=0 && F_M!=0)
				year += 15;
		else if(F_E!=0 && F_S==0 && F_M!=0)
				year += 28;
		else if(F_E!=0 && F_S!=0 && F_M==0)
				year += 19;
//		printf("y = %d\n", year);
//		printf("%d %d %d\n", E, S, M);
	}
	printf("%d\n", year);

	return 0;
}