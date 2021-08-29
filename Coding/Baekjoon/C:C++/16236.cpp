#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define MAX 21

struct coordinate{
	int x, y;
};

struct vst{
	bool val;
	int depth;
};

struct tupl{
	int dist, x, y;
};

int N;
int cnt;
int weight;
int time_spend;
bool eatable;
vst visited[MAX][MAX];
coordinate baby_loc;

void reset(vst visited[][MAX]){
	for(int i = 0; i<MAX; ++i){
		for(int j = 0; j<MAX; ++j){
			visited[i][j].val = false;
			visited[i][j].depth = 0;
		}
	}
}