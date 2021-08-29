#include <iostream>
#include <string>
using namespace std;
#define MAX 21

class node{
public:
	char key;
	bool visited;
	int move_depth;
};
class mov{
public:
	int x, y;
};

int R, C;
node brd[MAX][MAX];
int ovlap_check[26];
int max_depth;

// --------for debug---------------
void print_key(){
	for(int i = 0; i<R; ++i){
		for(int j = 0; j<C; ++j){
			if(brd[i][j].visited==true)
				printf("%c ", brd[i][j].key);
			else
				printf("* ");
		}printf("\n");
	}
	printf("\n");
}
void print_depth(){
	for(int i = 0; i<R; ++i){
		for(int j = 0; j<C; ++j){
			printf("%d ", brd[i][j].move_depth);
		}printf("\n");
	}
	printf("\n");
}
// ---------------------------------

void moving(int cur_r, int cur_c, int depth){
	mov m[4] = { {1,0},{0,1},{-1,0},{0,-1} };
// cout << "depth: " << depth << endl;
// print_key();
// print_depth();

	
	for(int i = 0; i<4; ++i){
		int nr = cur_r + m[i].x;
		int nc = cur_c + m[i].y;

		int order = (int)brd[nr][nc].key - (int)'A';

		if(nr>=0 && nc>=0 && nr<R && nc<C && ovlap_check[order]==0){
//printf("cur_r: %d, cur_c: %d, nr: %d, nc: %d\n", cur_r, cur_c, nr, nc);

			brd[nr][nc].visited = true;
			++ovlap_check[order];
			++depth;
			if(brd[nr][nc].move_depth < depth)
				brd[nr][nc].move_depth = depth;
			moving(nr, nc, depth);
//			brd[nr][nc].move_depth = 0;
			max_depth = depth;
			--depth;
			--ovlap_check[order];
			brd[nr][nc].visited = false;
		}
//		reset_array(ovlap_check, 26);
	}
}


int main(){

	cin >> R >> C;
	for(int i = 0; i<R; ++i){
		string input;
		cin >> input;
		for(int j = 0; j<C; ++j){
			brd[i][j].key = input[j];
//			int aschi = (int)brd[i][j] - (int)'A';
//			ovlap_check[aschi] = true;
		}
	}
	brd[0][0].move_depth = 1;
	brd[0][0].visited = true;
	int order = (int)brd[0][0].key - (int)'A';
	++ovlap_check[order];

	moving(0, 0, 1);

	int ans = 0;
	for(int i = 0; i<R; ++i){
		for(int j = 0; j<C; ++j){
			if(ans < brd[i][j].move_depth)
				ans = brd[i][j].move_depth;
		}
	}

	cout << ans << endl;

	return 0;
}