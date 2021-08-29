#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 26

int cnt;
bool visited[MAX][MAX];
struct mov{
	int x, y;
};
vector<int> v;


void apt(int arr[][MAX], int N, int a, int b){
	mov m[4] = { {1,0},{0,1},{-1,0},{0,-1} };
	queue< pair<int, int> > q;
	int tmp = 0;

	q.push({a, b});
	visited[a][b] = true;
	++tmp;

	while(!(q.empty()==true)){

		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for(int i = 0; i<4; ++i){
			int nx = cur_x + m[i].x;
			int ny = cur_y + m[i].y;

			if(nx>=0 && ny>=0 && nx<N && ny<N && arr[nx][ny]!=0 && visited[nx][ny]==false){
				q.push({nx, ny});
				visited[nx][ny] = true;
				++tmp;
			}

		}
	}

	++cnt;
	v.push_back(tmp);
}


int main(){
	int N;
	char tmp_str[26];
	int arr[MAX][MAX] = {0, };
	cin >> N;
	for(int i = 0; i<N; ++i){
		scanf("%s", tmp_str);
		for(int j = 0; j<strlen(tmp_str); ++j){
			arr[i][j] = tmp_str[j]-'0';
		}
	}

	cnt = 0;

	for(int i = 0; i<N; ++i){
		for(int j = 0; j<N; ++j){
			if(arr[i][j]!=0 && visited[i][j]==false)
				apt(arr, N, i, j);
		}
	}

	sort(v.begin(), v.end());

	printf("%d\n", cnt);
	for(int i = 0; i<cnt; ++i){
		printf("%d\n", v[i]);
	}

	return 0;
}