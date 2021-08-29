#include <iostream>
#include <queue>
using namespace std;
#define MAX 301

struct mov{
	int x, y;
};
struct cell{
	int h, near;
};

int N, M;
cell map[MAX][MAX];
bool visited[MAX][MAX];
int ice_cnt;
mov test_ice;
bool test_flag;
bool zero_flag;

// void mapprint(){
// 	for(int i = 0; i<N; ++i){
// 		for(int j = 0; j<M; ++j){
// 			cout << map[i][j].h << " ";
// 		}
// 		cout << endl;
// 	}
// }

void reset_visited(){
	for(int i = 0; i<N; ++i){
		for(int j = 0; j<M; ++j){
			visited[i][j] = false;
		}
	}
}

void melt(){
	mov m[4] = { {-1,0},{0,-1},{1,0},{0,1} };

	for(int i = 0; i<N; ++i){
		for(int j = 0; j<M; ++j){
			if(map[i][j].h>0){
				for(int k = 0; k<4; ++k){
					int nx = i + m[k].x;
					int ny = j + m[k].y;

					if(nx>=0 && ny>=0 && nx<N && ny<M && map[nx][ny].h<=0){
						++map[i][j].near;
					}
				}
			}
		}
	}

	for(int i = 0; i<N; ++i){
		for(int j = 0; j<M; ++j){
			map[i][j].h -= map[i][j].near;
			if(map[i][j].h < 0){
				map[i][j].h = 0;
			}
			if(map[i][j].h > 0 && test_flag == false){
				test_ice = {i,j};
				test_flag = true;
			}
			if(map[i][j].h > 0)
				++ice_cnt;
			map[i][j].near = 0;
		}
	}

	if(ice_cnt == 0)
		zero_flag = true;
}

bool one_test(){
	mov m[4] = { {-1,0},{0,-1},{1,0},{0,1} };
	int test_cnt = 0;

	queue< pair<int,int> > q;
	q.push(make_pair(test_ice.x, test_ice.y));
	visited[test_ice.x][test_ice.y] = true;

	while(q.empty()==false){
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		++test_cnt;
		q.pop();

		for(int i = 0; i<4; ++i){
			int nx = cur_x + m[i].x;
			int ny = cur_y + m[i].y;

			if(nx>=0 && ny>=0 && nx<N && ny<M && map[nx][ny].h>0 && visited[nx][ny]==false){
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
	reset_visited();
	test_flag = false;

	if(test_cnt==ice_cnt)
		return true;

	return false;
}

int main(){

	cin >> N >> M;
	for(int i = 0; i<N; ++i){
		for(int j = 0; j<M; ++j){
			cin >> map[i][j].h;

			if(map[i][j].h > 0 && test_flag==false){
				test_ice = {i,j};
				test_flag = true;
			}

			if(map[i][j].h > 0){
				++ice_cnt;
			}
		}
	}

	int year_cnt = 0;
	while(one_test()==true){
		ice_cnt = 0;
		melt();
		++year_cnt;
//		mapprint(); cout << endl;
	}
	if(zero_flag==true){
		year_cnt = 0;
	}

	cout << year_cnt << endl;

	return 0;
}