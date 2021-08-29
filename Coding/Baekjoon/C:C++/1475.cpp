#include <iostream>
#include <string>
using namespace std;

int main(){

	string dasom;
	cin >> dasom;

	int number_cnt[10] = {0, };

	for(int i = 0; dasom[i]!='\0' ; ++i){
		int num = (int)(dasom[i] - '0');
		++number_cnt[num];
	}

	number_cnt[6] = (int)((number_cnt[6]+number_cnt[9]+1)/2);

	int set_cnt = 0;
	for(int i = 0; i<9; ++i){
		if(number_cnt[i] > set_cnt){
			set_cnt = number_cnt[i];
		}
	}

	cout << set_cnt << endl;

	return 0;	
}