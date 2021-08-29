#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 301

struct loc{
	int x, y;
};

struct vst{
	bool val;
	int depth;
};

vst visited[MAX][MAX];

vector<int> testcase;

void reset(vst visited[][MAX]){
	for(int i = 0; i<MAX; ++i){
		for(int j = 0; j<MAX; ++j){
			visited[i][j].val = false;
			visited[i][j].depth = 0;
		}
	}
}


void PRINT(vst visited[][MAX], int I){
	for(int i = 0; i<I; ++i){
		for(int j = 0; j<I; ++j){
			printf("%d ", visited[i][j].depth);
		}
		printf("\n");
	}
}


void knikghtmove(int I, loc src, loc dst){
	loc m[8] = { {1,2},{2,1},{-1,2},{-2,1},{1,-2},{2,-1},{-1,-2},{-2,-1} };
	queue< pair<int,int> > q;

	q.push(make_pair(src.x,src.y));
	visited[src.x][src.y].val = true;

	while(!(q.empty()==true)){
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for(int i = 0; i<8; ++i){
			int nx = cur_x + m[i].x;
			int ny = cur_y + m[i].y;

			if(nx>=0 && ny>=0 && nx<I && ny<I && visited[nx][ny].val==false){
				q.push(make_pair(nx,ny));
				visited[nx][ny].val = true;
				visited[nx][ny].depth = visited[cur_x][cur_y].depth+1;
			}
			if(nx==dst.x && ny==dst.y){
				return ;
			}
		}
	}

}

int main(){
	
	reset(visited);

	int N;
	int I;
	loc src, dst;

	cin >> N;

	while(N!=0){

//		cout << "N: " << N << endl;

		cin >> I;

		cin >> src.x >> src.y;

		cin >> dst.x >> dst.y;


		knikghtmove(I, src, dst);

		cout << visited[dst.x][dst.y].depth << endl;
//PRINT(visited, I);
//printf("\n");
		N--;

		reset(visited);
	}

	return 0;
}