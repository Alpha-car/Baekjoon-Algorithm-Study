#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

struct MOV{
	int x, y;
};
int mat[MAX][MAX] = {0, };
bool visited[MAX][MAX] = {0, };
int N;
int ans;
int cnt;

void test_print(int mat[][MAX]){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

void search(int a, int b, int h)
{
	MOV m[4] = { {1,0},{0,1},{-1,0},{0,-1} };
	queue< pair<int, int> > q;

	visited[a][b] = true;
	q.push(make_pair(a, b));


	while(!(q.empty()==true)){
		
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for(int i = 0; i < 4; ++i){
			int nx = x + m[i].x;
			int ny = y + m[i].y;

			if(nx>=0 && ny>=0 && nx<N && ny<N && visited[nx][ny]==false && mat[nx][ny] > h){
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}

		}
	}
	++cnt;

}


int main()
{
	cin >> N;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			scanf("%d", &mat[i][j]);
//			cin >> mat[i][j];
		}
	}
//	test_print(arr);

	cnt = 0;
	ans = 0;

	for(int h = 0; h<=100; ++h){
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				if(mat[i][j] > h && visited[i][j]==false){
					search(i, j, h);
				}
			}
		}
		if(ans<cnt){
			ans = cnt;
		}
		cnt = 0;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				visited[i][j] = false;
			}
		}
	}


	printf("%d\n", ans);
//	cout << ans << endl;


	return 0;
}