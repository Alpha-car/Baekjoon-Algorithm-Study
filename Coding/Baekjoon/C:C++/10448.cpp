#include <iostream>
using namespace std;
#define MAX 45

int t[MAX];

void define_t(){
	for(int i = 1; i<MAX; ++i){
		t[i] = t[i-1] + i;
	}
}

bool test(int num){
	for(int i = 1; i<MAX; ++i){
		for(int j = 1; j<MAX; ++j){
			for(int k = 1; k<MAX; ++k){
				if(num == t[i]+t[j]+t[k])
					return true;
			}
		}
	}
	return false;
}

int main(){
	int N;
	cin >> N;

	define_t();

	int testcase;
	for(int i = 0; i<N; ++i){
		cin >> testcase;

		if(test(testcase)==true)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

	return 0;
}
/*
2000 = n*n+1
44*45
*/