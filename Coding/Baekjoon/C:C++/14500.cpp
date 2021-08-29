#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 501

int N, M;
int map[MAX][MAX];

int type_zero(){
	int maxi = 0;

	for(int i = 0; i<N; ++i){
		for(int j = 0; j<M-3; ++j){
			int sum = map[i][j]+map[i][j+1]+map[i][j+2]+map[i][j+3];
			if(maxi < sum){ maxi = sum; }
		}
	}
	for(int i = 0; i<N-3; ++i){
		for(int j = 0; j<M; ++j){
			int sum = map[i][j]+map[i+1][j]+map[i+2][j]+map[i+3][j];
			if(maxi < sum){ maxi = sum; }
		}
	}
	return maxi;
}

int type_one(){
	int maxi = 0;

	for(int i = 0; i<N-1; ++i){
		for(int j = 0; j<M-1; ++j){
			int sum = map[i][j]+map[i][j+1]+map[i+1][j]+map[i+1][j+1];
			if(maxi < sum){ maxi = sum; }
		}
	}

	return maxi;
}

int type_two(){
	int maxi = 0;

	int sum[4] = {0, };
	for(int i = 0; i<N-1; ++i){
		for(int j = 0; j<M-2; ++j){
			sum[0] = map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j+2];
			sum[1] = map[i][j]+map[i+1][j]+map[i+1][j+1]+map[i+1][j+2];
			sum[2] = map[i+1][j]+map[i+1][j+1]+map[i+1][j+2]+map[i][j+2];
			sum[3] = map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j];
			sort(sum, sum+4);
			if(maxi < sum[3]){ maxi = sum[3]; }
		}
	}
	for(int i = 0; i<N-2; ++i){
		for(int j = 0; j<M-1; ++j){
			sum[0] = map[i][j+1]+map[i+1][j+1]+map[i+2][j+1]+map[i+2][j];
			sum[1] = map[i][j]+map[i][j+1]+map[i+1][j]+map[i+2][j];
			sum[2] = map[i][j]+map[i+1][j]+map[i+2][j]+map[i+2][j+1];
			sum[3] = map[i][j]+map[i][j+1]+map[i+1][j+1]+map[i+2][j+1];
			sort(sum, sum+4);
			if(maxi < sum[3]){ maxi = sum[3]; }
		}
	}

	return maxi;
}

int type_three(){
	int maxi = 0;

	int sum[2] = {0, };
	for(int i = 0; i<N-2; ++i){
		for(int j = 0; j<M-1; ++j){
			sum[0] = map[i][j]+map[i+1][j]+map[i+1][j+1]+map[i+2][j+1];
			sum[1] = map[i][j+1]+map[i+1][j]+map[i+1][j+1]+map[i+2][j];
			sort(sum, sum+2);
			if(maxi < sum[1]){ maxi = sum[1]; }
		}
	}
	for(int i = 0; i<N-1; ++i){
		for(int j = 0; j<M-2; ++j){
			sum[0] = map[i][j+1]+map[i][j+2]+map[i+1][j]+map[i+1][j+1];
			sum[1] = map[i][j]+map[i][j+1]+map[i+1][j+1]+map[i+1][j+2];
			sort(sum, sum+2);
			if(maxi < sum[1]){ maxi = sum[1]; }
		}
	}

	return maxi;
}

int type_four(){
	int maxi = 0;

	int sum[2] = {0, };
	for(int i = 0; i<N-1; ++i){
		for(int j = 0; j<M-2; ++j){
			sum[0] = map[i][j]+map[i][j+1]+map[i][j+2]+map[i+1][j+1];
			sum[1] = map[i+1][j]+map[i][j+1]+map[i+1][j+1]+map[i+1][j+2];
			sort(sum, sum+2);
			if(maxi < sum[1]){ maxi = sum[1]; }
		}
	}
	for(int i = 0; i<N-2; ++i){
		for(int j = 0; j<M-1; ++j){
			sum[0] = map[i][j+1]+map[i+1][j]+map[i+1][j+1]+map[i+2][j+1];
			sum[1] = map[i][j]+map[i+1][j]+map[i+1][j+1]+map[i+2][j];
			sort(sum, sum+2);
			if(maxi < sum[1]){ maxi = sum[1]; }
		}
	}

	return maxi;
}

int main(){

	cin >> N >> M;
	for(int i = 0; i<N; ++i){
		for(int j = 0; j<M; ++j){
			cin >> map[i][j];
		}
	}

	int type[5] = {0, };

	type[0] = type_zero();
	type[1] = type_one();
	type[2] = type_two();
	type[3] = type_three();
	type[4] = type_four();
	sort(type, type+5);

	cout << type[4] << endl;

	return 0;
}