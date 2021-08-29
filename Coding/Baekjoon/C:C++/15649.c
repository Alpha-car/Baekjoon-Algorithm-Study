#include <stdio.h>

void DFS(int arr[8], int depth, int is_visited[8], int N, int M)
{
	if(depth == M){
		for(int i = 0; i<M; ++i){
			if(arr[i]!=0)
				printf("%d ", arr[i]);
		}
		printf("\n");
		return ;
	}

	for(int i = 0; i<N; ++i){
		if(is_visited[i]==0){
			arr[depth] = i+1;
			is_visited[i] = 1;
			DFS(arr, ++depth, is_visited, N, M);
			--depth;
			is_visited[i] = 0;
		}

	}
}

int main(void)
{
	int N, M;
	int depth = 0;
	int arr[8] = {0, };
	int is_visited[8] = {0, };

	scanf("%d%d", &N, &M);

	DFS(arr, depth, is_visited, N, M);

	return 0;
}