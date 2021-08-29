#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 51

struct mov{
	int x, y;
};

int w, h;

vector<int> v;

void clear(int mat[][MAX], bool flag[][MAX]){
	for(int i = 0; i<MAX; ++i){
		for(int j = 0; j<MAX; ++j){
			mat[i][j] = 0;
			flag[i][j] = false;
		}
	}
}

void land(int a, int b, int h, int w, int map[][MAX], bool checked[][MAX]){

	mov m[8] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
	queue< pair<int, int> > q;

	q.push(make_pair(a,b));
	checked[a][b] = true;

	while(!(q.empty()==true)){

		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for(int i = 0; i<8; ++i){
			int nx = cur_x + m[i].x;
			int ny = cur_y + m[i].y;

			if(nx>=0 && ny>=0 && nx<h && ny<w && map[nx][ny]==1 && checked[nx][ny]==false){
				q.push(make_pair(nx,ny));
				checked[nx][ny] = true;
			}
		}
	}
}

int main(){
	while(1){
		
		int map[MAX][MAX] = {0, };
		bool checked[MAX][MAX];
		int cnt = 0;

		cin >> w >> h;
		if(w==0 && h==0)
			break;

		for(int i = 0; i<h; ++i){
			for(int j = 0; j<w; ++j){
				cin >> map[i][j]; 
				checked[i][j] = false;
			}
		}

		for(int i = 0; i<h; ++i){
			for(int j = 0; j<w; ++j){
				if(map[i][j]==1 && checked[i][j]==false){
					land(i, j, h, w, map, checked);
					cnt++;
				}
			}
		}
		v.push_back(cnt);

		clear(map, checked);
	}

	for(int i = 0; i<v.size(); ++i){
		printf("%d\n", v[i]);
	}

	return 0;
}
