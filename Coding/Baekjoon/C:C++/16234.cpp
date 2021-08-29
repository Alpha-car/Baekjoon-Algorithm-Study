#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
#define MAX 51

struct mov{
	int x, y;
};

class nation{
public:
	int pop;
	bool visited;
};

int N, L, R;
nation A[MAX][MAX];

void testprint(){
	cout << endl;
	for(int i = 0; i<N; ++i){
		for(int j = 0; j<N; ++j){
			cout << A[i][j].pop << " ";
		}cout << endl;
	}cout << endl;
}

void reset(){
	for(int i = 0; i<N; ++i){
		for(int j = 0; j<N; ++j){
			A[i][j].visited = false;
		}
	}
}

bool move_possible(int cur_x, int cur_y, int nx, int ny){
	int gap = abs(A[cur_x][cur_y].pop - A[nx][ny].pop);
	if(gap>=L && gap<=R)
		return true;
	return false;
}

bool none_move_flag;
void BFS(int a, int b){
	mov m[4] = { {1,0},{0,1},{-1,0},{0,-1} };
	queue< pair<int,int> > q;
	q.push(make_pair(a,b));
	A[a][b].visited = true;

	int union_pop = 0;
	vector< pair<int,int> > union_index;

	while(q.empty()==false){
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		union_pop += A[cur_x][cur_y].pop;
		union_index.push_back(make_pair(cur_x,cur_y));
		q.pop();

		for(int i = 0; i<4; ++i){
			int nx = cur_x + m[i].x;
			int ny = cur_y + m[i].y;

			if(nx>=0 && ny>=0 && nx<N && ny<N && A[nx][ny].visited==false && move_possible(cur_x, cur_y, nx, ny)){
				q.push(make_pair(nx,ny));
				A[nx][ny].visited = true;	
				none_move_flag = false;
			}
		}
	}
	int after_pop = (int)union_pop/union_index.size();
	for(int i = 0; i<(int)union_index.size(); ++i){
		A[union_index[i].first][union_index[i].second].pop = after_pop;
	}
}

int main(){

	cin >> N >> L >> R;

	for(int i = 0; i<N; ++i){
		for(int j = 0; j<N; ++j){
			cin >> A[i][j].pop;
		}
	}
	int day_cnt = 0;
	
	while(none_move_flag==false){

		none_move_flag = true;
		for(int i = 0; i<N; ++i){
			for(int j = 0; j<N; ++j){
				if(A[i][j].visited==false){
					BFS(i, j);
				}
			}
		}

		if(none_move_flag==false){
			day_cnt++;
		}
		reset();
	}

	cout << day_cnt << endl;
	return 0;
}