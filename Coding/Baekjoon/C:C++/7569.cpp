#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
#define MAX 101

class mov{
public:
	int h, n, m;
};
class node{
public:
	int key, depth;
	bool visited;
};

int M, N, H, unreap_cnt, max_depth;
queue< tuple<int,int,int,int> > q;	// height, n, m, depth

node box[MAX][MAX][MAX];

void BFS(mov m[]){

	while(q.empty()==false){
		int cur_h = get<0>(q.front());
		int cur_n = get<1>(q.front());
		int cur_m = get<2>(q.front());
		int cur_depth = get<3>(q.front());
		q.pop();

		for(int i = 0; i<6; ++i){
			int nh = cur_h + m[i].h;
			int nn = cur_n + m[i].n;
			int nm = cur_m + m[i].m;
			int ndepth = cur_depth + 1;

			if(nh >= 0 && nn >= 0 && nm >= 0 && nh < H && nn < N && nm < M 
				&& box[nh][nn][nm].visited == false && box[nh][nn][nm].key == 0){
				q.push(make_tuple(nh,nn,nm,ndepth));
				box[nh][nn][nm].visited = true;
				box[nh][nn][nm].key = 1;
				unreap_cnt--;
				// if(ndepth > box[nh][nn][nm].depth){
				// 	box[nh][nn][nm].depth = ndepth;
				// }
				if(max_depth < ndepth){
					max_depth = ndepth;
				}
			}
		}
	}
	if(unreap_cnt != 0){
		max_depth = -1;
	}
}

int main(){

	mov m[6] = { {-1,0,0},{1,0,0},{0,0,-1},{0,0,1},{0,-1,0},{0,1,0} };

	cin >> M >> N >> H;

	for(int i = 0; i<H; ++i){
		for(int j = 0; j<N; ++j){
			for(int k = 0; k<M; ++k){
				cin >> box[i][j][k].key;
				if(box[i][j][k].key == 1){
					q.push(make_tuple(i,j,k,0));
				}
				if(box[i][j][k].key == 0){
					unreap_cnt++;
				}
			}
		}
	}

	BFS(m);

	cout << max_depth << endl;

	return 0;
}
