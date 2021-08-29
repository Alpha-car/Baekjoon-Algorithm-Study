#include <iostream>
#include <cstring>
using namespace std;
#define MAX 51

int N;


bool valid_test(char ps[]){
	int tmp = 0;

	for(int i = 0; i<strlen(ps); ++i){
		if(ps[i]=='(')
			tmp++;
		else if(ps[i]==')')
			tmp--;
		if(tmp<0)
			return false;
	}
	if(tmp==0)
		return true;
	return false;
}


int main(){

	cin >> N;

	char ps[51] = {0, };

	for(int i = 0; i<N; ++i){
		scanf("%s", ps);

		if(valid_test(ps)==true){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}

	return 0;
}