#include <stdio.h>
#define MAX 17

int Roman_NUM(char str[])
{
	int i;
	int num = 0;
	for(i=0;str[i]!='\0';++i){
		if(str[i] == 'M'){
			num += 1000;
		}
		else if(str[i] == 'D'){
			num += 500;
		}
		else if(str[i] == 'C'){
			if(str[i+1] == 'M'){
				num += 900;
				i++;
			}
			else if(str[i+1] == 'D'){
				num += 400;
				i++;
			}
			else{
				num += 100;
			}
		}
		else if(str[i] == 'L'){
			num += 50;
		}
		else if(str[i] == 'X'){
			if(str[i+1] == 'C'){
				num += 90;
				i++;
			}
			else if(str[i+1] == 'L'){
				num += 40;
				i++;
			}
			else{
				num += 10;
			}
		}
		else if(str[i] == 'V'){
			num += 5;
		}
		else if(str[i] == 'I'){
			if(str[i+1] == 'X'){
				num += 9;
				i++;
			}
			else if(str[i+1] == 'V'){
				num += 4;
				i++;
			}
			else{
				num += 1;
			}
		}
	}
	return num;
}

void print_Roman_NUM(int num)
{
	while(1){
		if(num>=1000){
			printf("M");
			num -= 1000;
		}
		else if(num>=100){
			if(num/100==9){
				printf("CM");
				num -= 900;
			}
			else if(num/100>=5){
				printf("D");
				num -= 500;
			}
			else if(num/100==4){
				printf("CD");
				num -= 400;
			}
			else{
				printf("C");
				num -= 100;
			}
		}
		else if(num>=10){
			if(num/10==9){
				printf("XC");
				num -= 90;
			}
			else if(num/10>=5){
				printf("L");
				num -= 50;
			}
			else if(num/10==4){
				printf("XL");
				num -= 40;
			}
			else{
				printf("X");
				num -= 10;
			}
		}
		else{
			if(num==9){
				printf("IX");
				num -= 9;
			}
			else if(num>=5){
				printf("V");
				num -= 5;
			}
			else if(num==4){
				printf("IV");
				num -= 4;
			}
			else{
				printf("I");
				num -= 1;
			}
		}
		if(num==0) break;
	}
	printf("\n");
}

int main(void)
{
	int A, B;
	char str[MAX]; //		 make a room for string

	scanf("%s", str);
	A = Roman_NUM(str);
	scanf("%s", str);
	B = Roman_NUM(str);
//	printf("%d %d\n", A, B);
	printf("%d\n", A+B);
	print_Roman_NUM(A+B);
	
	return 0;
}

/*
3888 = MMMDCCCLXXXVIII 15ea

*/