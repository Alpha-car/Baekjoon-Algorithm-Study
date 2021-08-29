#include <stdio.h>

int main(void)
{
	char str[102];
	int i;
	int cnt = 0;

	scanf("%s", str);
	for(i=0;str[i]!='\0';++i){
		if(str[i] == 'c'){
			if(str[i+1] == '='){
				cnt++;
				i++;
			}
			else if(str[i+1] == '-'){
				cnt++;
				i++;
			}
			else{
				cnt++;
			}
		}
		else if(str[i] == 'd'){
			if(str[i+1] == 'z'){
				if(str[i+2] == '='){
					cnt++;
					i += 2;
				}
				else{
					cnt += 2;
					i++;
				}
			}
			else if(str[i+1] == '-'){
				cnt++;
				i++;
			}
			else{
				cnt++;
			}
		}
		else if(str[i] == 'l'){
			if(str[i+1] == 'j'){
				cnt++;
				i++;
			}
			else{
				cnt++;
			}
		}		
		else if(str[i] == 'n'){
			if(str[i+1] == 'j'){
				cnt++;
				i++;
			}
			else{
				cnt++;
			}
		}
		else if(str[i] == 's'){
			if(str[i+1] == '='){
				cnt++;
				i++;
			}
			else{
				cnt++;
			}
		}
		else if(str[i] == 'z'){
			if(str[i+1] == '='){
				cnt++;
				i++;
			}
			else{
				cnt++;
			}
		}
		else
			cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}


/*
c= -> 27
c- -> 28
dz= -> 29
d- -> 30
lj -> 31
nj -> 32
s= -> 33
z= -> 34
*/