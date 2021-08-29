#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 51

int R, C;
queue< tuple<int, int, int> > q;

struct MOV{
	int x, y;
};

void PRINT(int arr[][MAX]){
	for(int i = 0; i<R; ++i){
		for(int j = 0; j<C; ++j){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void push_air(int loc, int arr[][MAX]){
	int loc_up = loc-1;
	int loc_down = loc;
	int tmp[MAX][MAX] = {0, };
	for(int i = 0; i<R; ++i){
		for(int j = 0; j<C; ++j){
			tmp[i][j] = arr[i][j];
		}
	}

	tmp[loc_up][0] = 0;
	for(int i = 1; i<C; ++i){
		arr[loc_up][i] = tmp[loc_up][i-1];
	}
	for(int i = loc_up-1; i>=0; --i){
		arr[i][C-1] = tmp[i+1][C-1];
	}
	for(int i = C-2; i>=0; --i){
		arr[0][i] = tmp[0][i+1];
	}
	for(int i = 1; i<loc_up+1; ++i){
		arr[i][0] = tmp[i-1][0];
	}
	arr[loc_up][0] = -1;

	tmp[loc_down][0] = 0;
	for(int i = 1; i<C; ++i){
		arr[loc_down][i] = tmp[loc_down][i-1];
	}
	for(int i = loc_down+1; i<R; ++i){
		arr[i][C-1] = tmp[i-1][C-1];
	}
	for(int i = C-2; i>=0; --i){
		arr[R-1][i] = tmp[R-1][i+1];
	}
	for(int i = R-2; i>=loc_down; --i){
		arr[i][0] = tmp[i+1][0];
	}
	arr[loc_down][0] = -1;
}

void after_time(int T, int arr[][MAX], int loc, int depth){
//printf("depth : %d\n", depth);
	if(depth == T){
		int amount = 0;
		for(int i = 0; i<R; ++i){
			for(int j = 0; j<C; ++j){
				if(arr[i][j]>0)
					amount += arr[i][j];
			}
		}
		cout << amount << endl;
		return ;
	}
	

	MOV m[4] = { {1,0},{0,1},{-1,0},{0,-1} };

//printf("\n**T : %d\n", T);
	int size = q.size();
	for(int i = 0; i<size; ++i){
		int cur_x = get<0>(q.front());
		int cur_y = get<1>(q.front());
		int cur_z = get<2>(q.front());
		q.pop();
//printf("cur : (%d,%d)\n", cur_x, cur_y);
		int tmp = cur_z;
		for(int j = 0; j<4; ++j){
			int nx = cur_x + m[j].x;
			int ny = cur_y + m[j].y;
			if(nx>=0 && nx<R && ny>=0 && ny<C && arr[nx][ny]!=-1){
				//printf("???\n");
				arr[nx][ny] += tmp/5;
//printf("arr[cur_x][cur_y] : %d\n", arr[cur_x][cur_y]);
//printf("arr[cur_x][cur_y]/5 : %d\n", arr[cur_x][cur_y]/5);
				arr[cur_x][cur_y] -= tmp/5;
				if(arr[cur_x][cur_y]>0)
					q.push({cur_x,cur_y,tmp/5});
				if(arr[nx][ny]>0)
					q.push({nx,ny,arr[nx][ny]});
			}
		}
	}
//printf("\n");
//PRINT(arr);		
	push_air(loc, arr);
//printf("-->\n");
//PRINT(arr);
//printf("\n");

	while(!q.empty()){
		q.pop();
	}
	for(int i = 0; i<R; ++i){
		for(int j = 0; j<C; ++j){
			q.push({i,j,arr[i][j]});
		}
	}
	after_time(T, arr, loc, ++depth);
}

int main(){
	int T;
	int amount = 0;
	int loc;
	int arr[MAX][MAX];
	cin >> R >> C >> T;
	for(int i = 0; i<R; ++i){
		for(int j = 0; j<C; ++j){
			cin >> arr[i][j];
			if(arr[i][j]>0){
				amount += arr[i][j];
				q.push({i,j,arr[i][j]});
			}
			if(arr[i][j]==-1)
				loc = i;
		}
	}
	int depth = 0;
	after_time(T, arr, loc, depth);

	return 0;
}