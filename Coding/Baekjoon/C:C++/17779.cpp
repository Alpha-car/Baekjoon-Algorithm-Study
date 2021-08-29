#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 22


int A[MAX][MAX];
int N;
int ans;

void testprint(int test[][MAX]){
	for(int i = 1; i<=N; ++i){
		for(int j = 1; j<=N; ++j){
			cout << test[i][j] << " ";
		}cout << endl;
	}
}

void devide(int x, int y, int d1, int d2){
//	int test[MAX][MAX] = {0, };
	bool v1 = false, v2 = false, v3 = false, v4 = false, v5 = false;

	int election[5] = {0, };
	for(int r = 1; r<=N; ++r){
		for(int c = 1; c<=N; ++c){
			if(x+y<=r+c && r+c<=x+y+2*d2 && x-y<=r-c && r-c<=x-y+2*d1){
				election[4] += A[r][c];
//				test[r][c] = 5;
				v5 = true;
			}
			else if(1<=r && r<x+d1 && 1<=c && c<=y){
				election[0] += A[r][c];
//				test[r][c] = 1;
				v1 = true;
			}
			else if(1<=r && r<=x+d2 && y<c && c<=N){
				election[1] += A[r][c];
//				test[r][c] = 2;
				v2 = true;
			}
			else if(x+d1<=r && r<=N && 1<=c && c<y-d1+d2){
				election[2] += A[r][c];
//				test[r][c] = 3;
				v3 = true;
			}
			else if(x+d2<r && r<=N && y-d1+d2<=c && c<=N){
				election[3] += A[r][c];
//				test[r][c] = 4;
				v4 = true;
			}
		}
	}
	if(!(v1==true && v2==true && v3==true && v4==true && v5==true)){
		return ;
	}

	sort(election, election+5);
	int difference = election[4]-election[0];
//##debug 구간
	// cout << "election?" << election[0] << " " << election[4] << endl;
	// cout << "difference in x=" << x << ", y=" << y << ", d1=" << d1 << ", d2=" << d2 << endl;
	// cout << "	" << difference << endl;
	// testprint(test);
//
	if(ans > difference)
		ans = difference;
}

int main(){
	ans = 10000000;

	cin >> N;
	for(int i = 1; i<=N; ++i){
		for(int j = 1; j<=N; ++j){
			cin >> A[i][j];
		}
	}

	for(int i = 1; i<=N; ++i){
		for(int j = 1; j<=N; ++j){
			for(int k = 1; k<=N; ++k){
				for(int l = 1; l<=N; ++l){
					if(k>=1 && l>=1 && i+k+l<=N && 1<=j-k && j+l<=N){
						devide(i, j, k, l);
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
