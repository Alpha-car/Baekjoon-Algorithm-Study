#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

int ans, unrip;
bool visited[MAX][MAX];
//bool flag;
queue< pair<int, int> > q;

struct MOV{
	int x, y;
};

void print(int N, int M, int arr[][MAX]){
	for(int i = 0; i<N; ++i){
		for(int j = 0; j<M; ++j){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void bfs(int N, int M, int x, int y, int arr[][MAX]){
	MOV m[4] = { {1,0},{0,1},{-1,0},{0,-1} };

	q.push({x,y});
	visited[x][y] = true;

	while(!q.empty()){
		int size = q.size();
		for(int i = 0; i<size; ++i){
			
			//printf("\n%lu\n",q.size());

			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();
			
			//printf("<%d,%d>\n",cur_x+1,cur_y+1);

			for(int j = 0; j<4; ++j){
				int nx = cur_x + m[j].x;
				int ny = cur_y + m[j].y;
				
				if(nx>=0 && nx<N && ny>=0 && ny<M && arr[nx][ny]==0 && visited[nx][ny]==false){
				//printf("(%d,%d)\n",nx+1,ny+1);
					q.push({nx,ny});
					arr[nx][ny] = 1;
					visited[nx][ny] = true;
					--unrip;
					//printf("*unrip=%d\n",unrip);
					//flag = true;
				}
			}
		}
//cout << flag << endl;
		++ans;
//printf("unrip : %d, ans : %d\n", unrip, ans);
//print(N, M, arr);
//printf("\n");
		if(unrip==0){
			return ;
		}
	}
}


int main(){
//flag = false;
	ans = 0;
	unrip = 0;
	int N, M;
	cin >> M >> N;

	int arr[MAX][MAX];
	for(int i = 0; i<N; ++i){
		for(int j = 0; j<M; ++j){
			cin >> arr[i][j];
			
			if(arr[i][j]==1){
				q.push({i,j});
			}
			else if(arr[i][j]==0){
				++unrip;
			}
		}
	}
//printf("unrip_1st = %d\n", unrip);
	for(int i = 0; i<N; ++i){
		for(int j = 0; j<M; ++j){
			if(arr[i][j]==1 && unrip!=0){
				bfs(N, M, i, j, arr);
			}
		}
	}
//printf("%d %d\n", unrip, ans);
//print(N, M, arr);
	if(unrip==0){
		cout << ans << endl;
	}
	else{
		cout << -1 << endl;
	}
	return 0;
}