#include <iostream>
#include <queue>
using namespace std;
#define MAX 51
#define MOVE_ABLE nx>=0 && ny>=0 && nx<N && ny<M && room[nx][ny].wall==false

struct cell{
	bool vst, wall;
};

struct mov{
	int x, y, see;		// .see: 0-north, 1-east, 2-south, 3-west
};

mov m[4] = { {0,-1},{1,0},{0,1},{-1,0} };	// < v > ^

int N, M;
cell room[MAX][MAX];
mov RV;

int clean_cnt;


void testprint(int depth){
	printf("clean_cnt : %d\n", clean_cnt);
	printf("depth : %d\n", depth);
	if(RV.see == 0){ printf("RV.see : north\n"); }
	if(RV.see == 1){ printf("RV.see : east\n"); }
	if(RV.see == 2){ printf("RV.see : south\n"); }
	if(RV.see == 3){ printf("RV.see : west\n"); }
	for(int i = 0; i<N; ++i){
		for(int j = 0; j<M; ++j){
			if(i == RV.x && j == RV.y){
				printf("@ ");
			}
			else if(room[i][j].vst==true){
				printf("* ");
			}
			else{
				printf("%d ", room[i][j].wall);
			}
		}
		printf("\n");
	}
	printf("\n");
}


void near_search(int cur_x, int cur_y, int depth){
	if(depth == 4){
		int back = (5 - RV.see) % 4;	// a->b : 0->1 1->0 2->3 3->2 ... b=(5-a)%4
		int nx = cur_x + m[back].x;
		int ny = cur_y + m[back].y;
		if(MOVE_ABLE){
			RV.x = nx;
			RV.y = ny;
//			testprint(depth);
			near_search(RV.x, RV.y, 0);
			return ;
		}

		return ;
	}

	int left = (4 - RV.see) % 4;		// a->b : 0->0 1->3 2->2 3->1 ... b=(4-a)%4
	int nx = cur_x + m[left].x;
	int ny = cur_y + m[left].y;

	if(MOVE_ABLE && room[nx][ny].vst==false){
		RV.see = (RV.see + 3) % 4;
		RV.x = nx;
		RV.y = ny;
		// clean(RV.x, RV.y);
		room[RV.x][RV.y].vst = true;
		++clean_cnt;
//		testprint(depth);
		near_search(RV.x, RV.y, 0);
		return ;
	}
	else{
		RV.see = (RV.see + 3) % 4;
		near_search(RV.x, RV.y, ++depth);
		return ;
	}
}

void clean(int cur_x, int cur_y){
	room[cur_x][cur_y].vst = true;
	++clean_cnt;
//	testprint(0);

	near_search(RV.x, RV.y, 0);
}

int main(){

	cin >> N >> M;
	cin >> RV.x >> RV.y >> RV.see;

	for(int i = 0; i<N; ++i){		// north to south
		for(int j = 0; j<M; ++j){	// west to east
			cin >> room[i][j].wall;
		}
	}

	clean(RV.x, RV.y);

	cout << clean_cnt << endl;

	return 0;
}