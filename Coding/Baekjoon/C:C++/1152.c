#include <stdio.h>
#include <string.h>


int main(void)
{
	int word_cnt = 1;
	int tmp = 0;
	char str[1000001] = {0, };
	int length;
	int start, end;

	
	scanf("%[^\n]s", str);
	length = strlen(str);

	for(int i = 0; i<length; ++i){
		if(str[i] != ' '){
			start = i;
			break;
		}
	}
	for(int i = length-1; i>=0; --i){
		if(str[i] != ' '){
			end = i;
			break;
		}
	}

//	printf("start : %d\n", start);

	for(int i = start; i<=end; ++i){
		if(str[i] == ' '){
			word_cnt++;
		}
	}

	for(int i = 0; i<length; ++i){
		if(str[i] != ' '){
			tmp++;
		}
	}
	if(tmp == 0){
		word_cnt = 0;
	}

	printf("%d\n", word_cnt);
	return 0;
}