#include <iostream>
using namespace std;
#define MAX 11

int N;
int ans[MAX];

int main(){

	cin >> N;

	for(int i = 0; i<N; ++i){
		ans[i] = MAX;
	}

	for(int i = 0; i<N; ++i){
		int input;
		cin >> input;
		
		int cnt = -1;
		for(int j = 0; j<N; ++j){
			if(ans[j] > i+1){
				cnt++;
			}
			if(cnt==input){
				ans[j] = i+1;
				break;
			}
		}
	}

	for(int i = 0; i<N; ++i){
		cout << ans[i] << " ";
	}cout << endl;

	return 0;
}