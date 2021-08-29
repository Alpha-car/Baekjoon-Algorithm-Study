#include <stdio.h>
#define MAX 101

int cnt;

void Depth(int src, int arr[][MAX], int is_visited[MAX], int spot_num)
{
	++is_visited[src];
	++cnt;
	for(int i = 1; i<=spot_num; ++i){
		if(arr[src][i]==1 && is_visited[i]==0){
			Depth(i, arr, is_visited, spot_num);
		}
	}
}

int main(void)
{
	int N;
	int line;
	int arr[MAX][MAX] = {0, };
	int a, b;
	int is_visited[MAX] = {0, };
	cnt = 0;

	scanf("%d", &N);
	scanf("%d", &line);

	for(int i = 0; i<line; ++i){
		scanf("%d%d", &a, &b);
		
			arr[a][b] = 1;
			arr[b][a] = 1;
	}
/*
	for(int i = 1; i<=N; ++i){
		for(int j = 1; j<=N; ++j){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
*/
	is_visited[1] = 1;
	for(int i = 2; i<+N; ++i){
		if(arr[1][i]==1 && is_visited[i]==0){
			Depth(i, arr, is_visited, N);
		}
	}

	printf("%d\n", cnt);


	return 0;
}