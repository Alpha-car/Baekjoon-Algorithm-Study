#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 102

int r, c, k;
int A[MAX][MAX];
int row, col;

void testprint(){
	cout << endl;
	for(int i = 0; i<row; ++i){
		for(int j = 0; j<col; ++j){
			cout << A[i][j] << " ";
		}cout << endl;
	}cout << endl;
}

void R_opr(){
	for(int i = 0; i<row; ++i){
		vector< pair<int,int> > freq;	// first : 빈도 수, second : 숫자
		bool visited[MAX] = {0, };

		for(int j = 0; j<col; ++j){
			if(A[i][j] > 0){
				if(visited[A[i][j]]==false){
					freq.push_back(make_pair(1,A[i][j]));
					visited[A[i][j]] = true;
				}
				else{
					int tmp = find_if(freq.begin(), freq.end(), [&](const pair<int,int>& element){return element.second == A[i][j];})-freq.begin();
					freq[tmp].first++;
				}
			}
		}
		sort(freq.begin(), freq.end());
		
		if(col < 2*freq.size()){
			col = 2*freq.size();
		}
		for(int j = 0; j<col; ++j){
			int tmp = j/2;
			if(j<2*freq.size()){
				if(j%2 == 0){
					A[i][j] = freq[tmp].second;
				}
				else if(j%2 == 1){
					A[i][j] = freq[tmp].first;
				}
			}
			else{
				A[i][j] = 0;
			}
		}
	}
}

void C_opr(){
	for(int i = 0; i<col; ++i){
		vector< pair<int,int> > freq;	// first : 빈도 수, second : 숫자
		bool visited[MAX] = {0, };

		for(int j = 0; j<row; ++j){
			if(A[j][i] > 0){
				if(visited[A[j][i]]==false){
					freq.push_back(make_pair(1,A[j][i]));
					visited[A[j][i]] = true;
				}
				else{
					int tmp = find_if(freq.begin(), freq.end(), [&](const pair<int,int>& element){return element.second == A[j][i];})-freq.begin();
					freq[tmp].first++;
				}
			}
		}
		sort(freq.begin(), freq.end());

		if(row < 2*freq.size()){
			row = 2*freq.size();
		}
		for(int j = 0; j<row; ++j){
			int tmp = j/2;
			if(j<2*freq.size()){
				if(j%2 == 0){
					A[j][i] = freq[tmp].second;
				}
				else if(j%2 == 1){
					A[j][i] = freq[tmp].first;
				}
			}
			else{
				A[j][i] = 0;
			}
		}
	}
}

int main(){

	cin >> r >> c >> k;
	r--; c--;
	for(int i = 0; i<3; ++i){
		for(int j = 0; j<3; ++j){
			cin >> A[i][j];
		}
	}
	row = 3;
	col = 3;

	int time_cnt = 0;


	while(A[r][c]!=k){
		if(time_cnt >= 100){
			time_cnt = -1;
			break;
		}

		time_cnt++;

		if(row >= col){ R_opr(); }
		else if(row < col){ C_opr(); }
	}
	
	cout << time_cnt << endl;

	return 0;
}