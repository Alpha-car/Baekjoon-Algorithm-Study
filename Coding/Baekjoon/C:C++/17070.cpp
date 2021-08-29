#include <iostream>
#include <queue>
using namespace std;
#define MAX 18

struct mov{
	int x, y;
};

int N;
int stt[MAX][MAX];
bool visited[MAX][MAX];
int cnt;

void PRINT_VISIT(){
	for(int i = 1; i<=N; ++i){
		for(int j = 1; j<=N; ++j){
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
}

void pipe(int cur_x, int cur_y, int status, int depth){
	if(cur_x==N && cur_y==N){
		cnt++;
//printf("\ncnt = %d\n", cnt);
	}

	mov m[3] = { {0,1},{1,1},{1,0} };
	
//	printf("ns??? : %d\n", status);
//	bool flag = false;

/*	if(status==0 && stt[cur_x][cur_y+1]==1)
		return ;
	if(status==0 && stt[cur_x+1][cur_y]==1)
		flag = true;*/

	for(int i = 0; i<=2; ++i){
//PRINT_VISIT();
//printf("ns????? : %d 		i : %d\n", status, i);
		if(i==0 && status==2){
//			printf("*");
			i = 1;
		}
		if(i==2 && status==0){
//printf("ns였던 것 : %d\n\n", status);
			break;
		}
/*		if(i!=0 && flag==true)
			break;*/
//PRINT_VISIT();
//printf("%d \n", i);
//printf("depth : %d\n", depth);
		int nx = cur_x + m[i].x;
		int ny = cur_y + m[i].y;
		int ns = -1;
//printf("%d. %d", nx, ny);
		if(nx>=1 && ny>=1 && nx<=N && ny<=N && stt[nx][ny]!=1 && visited[nx][ny]==false){
//printf("(%d,%d)->(%d,%d)\n", cur_x, cur_y, nx, ny);				
			if(cur_x==nx && cur_y!=ny)
				ns = 0;
			else if(cur_x!=nx && cur_y!=ny)
				ns = 1;
			else if(cur_x!=nx && cur_y==ny)
				ns = 2;
//printf("ns : %d\n", ns);

			if(ns == 1 && (stt[nx-1][ny]==1 || stt[nx][ny-1]==1)){
//				printf("stat : %d\ni==%d\n", status, i);
				continue ;
			}

			visited[nx][ny] = true;
			++depth;
//PRINT_VISIT();
//printf("\n");
			pipe(nx,ny,ns,depth);
			--depth;
			visited[nx][ny] = false;
		}
//PRINT_VISIT();
//		printf("hh%d\n", i);
//		else
//			printf("펑!\n\n");
	}
}

int main(){

	scanf("%d", &N);

	for(int i = 1; i<=N; ++i){
		for(int j = 1; j<=N; ++j)
			scanf("%d", &stt[i][j]);
	}

	cnt = 0;
	int depth = 0;

	visited[1][1] = true;
	visited[1][2] = true;

	pipe(1,2,0,depth);

	printf("%d\n", cnt);

	return 0;
}