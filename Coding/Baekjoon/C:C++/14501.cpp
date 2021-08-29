#include <iostream>
using namespace std;
#define MAX 16

int N;
int T[MAX];
int P[MAX];
int day_max;
int pay;

void max_count(int starter, int tmppay, int cnt){
	int i;

	for(i = starter; i<N; ++i){
		if(i+T[i]==N){
			++cnt;
			tmppay += P[i];
			if(day_max < cnt)
				day_max = cnt;
			if(pay<tmppay)
				pay = tmppay;
		
			--cnt;
			tmppay -= P[i];
			continue;
		}

		if(i+T[i]>N){
			continue;
		}

		++cnt;
		tmppay += P[i];
		max_count(i+T[i], tmppay, cnt);
		--cnt;
		tmppay -= P[i];
	}

	if(day_max < cnt)
		day_max = cnt;
	if(pay < tmppay)
		pay = tmppay;
	return ;
}

int main(){
	
	cin >> N;

	for(int i = 0; i<N; ++i){
		cin >> T[i] >> P[i];
	}

	max_count(0, 0, 0);	

	cout << pay << endl;

	return 0;
}