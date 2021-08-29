#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int less_odd(char str[], int cntstr[], int N)
{
	int i;
	int cnt = 0;

	for(i=0;i<26;++i){
		if(cntstr[i]%2==1)
			cnt++;
	}
	if(cnt <= 1)
		return 1;	//TRUE
	return 0;		//FALSE
}

void printf_in_1st_case(char half[], int cntstr[], int NN, int ot)
{
	int i, j=0;
	int tmp[26];
	char alp;

	for(i=0;i<26;++i){
		tmp[i] = cntstr[i];
	}
//	printf("NN = %d\n", NN);
	for(i=0;i<NN-1;++i){
		for(j=0;j<26;++j){
			if(tmp[j]!=0){
				alp = (char)j+65;
				half[i] = alp;
				tmp[j]--;
//				printf("j= %d\n", j);
				break;
			}
		}
	}
	printf("%s", half);
	for(i=NN-2;i>=0;--i){
		printf("%c", half[i]);
	}
	printf("\n");

}
void printf_in_2nd_case(char half[], int cntstr[], int NN)
{
	int i, j=0;
	int tmp[26];
	char alp;

	for(i=0;i<26;++i){
		tmp[i] = cntstr[i];
	}
	for(i=0;i<NN;++i){
		for(j=0;j<26;++j){
			if(tmp[j]!=0){
				alp = (char)j+65;
				half[i] = alp;
				tmp[j]--;
//				printf("j= %d\n", j);
				break;
			}
		}
	}	
	printf("%s", half);
	for(i=NN-1;i>=0;--i){
		printf("%c", half[i]);
	}
	printf("\n");	

}

int main(void)
{



	char str[52] = {0, };
	int cntstr[26]={0, };
	char half[27] = {0, };
	int N, i, a, NN, ot;

	scanf("%s", str);
	N = strlen(str);

	for(i=0;i<N;++i){
		a = str[i]-65;
		cntstr[a]++;
	}

//	printf("N = %d\n", N);

	if(less_odd(str, cntstr, N) == 1){
		if(N%2 == 1){
			NN = N/2+1;
			for(i=0;i<26;++i){
				if(cntstr[i]%2 == 1){
					ot = i;
//					cntstr[i]--;
				}
				cntstr[i] = cntstr[i]/2;
			}
			half[NN-1] = ot+65;
//			printf("ot = %d\nhalf[NN-1] = %c\n", ot, half[NN-1]);
			printf_in_1st_case(half, cntstr, NN, ot);
		}
		else if(N%2 == 0){
			NN = N/2;
			for(i=0;i<26;++i){
				cntstr[i] = cntstr[i]/2;
			}
			printf_in_2nd_case(half, cntstr, NN);
		}
	}
	else
		printf("I'm Sorry Hansoo\n");




	return 0;
}



/*

odd time less than 1 alphabet
else this is impossible.

devide across the mid
string length = (string length)/2
first.string / second.string
1) there is an odd time
last factor of first.string : odd time
and arrange first.string
2) there is no odd time
arrange first.string

*/

/*
ABCD 1234 
ABDC 1243 
ACBD 1324 
ACDB 1342 
ADBC 1423 
ADCB 1432
*/
