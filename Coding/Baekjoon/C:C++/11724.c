#include <stdio.h>
#define MAX 1001

int ans;

void print_arr(int arr[MAX][MAX], int N)
{
	for(int i = 0; i<=N; ++i){
		for(int j = 0; j<=N; ++j){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void DFS(int arr[][MAX], int visited[MAX], int index, int N)
{
	visited[index] = 1;
//printf("index : %d\n", index);
	for(int i = 1; i<=N; ++i){
		if(arr[index][i]==1 && visited[i]==0){
			DFS(arr, visited, i, N);
		}
	}

}

int main(void)
{
	int N, M;
	int arr[MAX][MAX] = {0, };
	int visited[MAX] = {0, };
	int src, dst;
	int flag = 0;
	ans = 0;

	scanf("%d%d", &N, &M);
	for(int i = 0; i<M; ++i){
		scanf("%d%d", &src, &dst);

		arr[src][dst] = 1;
		arr[dst][src] = 1;
	
	}
//print_arr(arr, N);

	for(int i = 1; i<=N; ++i){
		for(int j = 1; j<=N; ++j){
			if(arr[i][j]!=0)
				flag = 1;
		}
		if(flag==0){
			++ans;
			visited[i]=1;
		}
		flag = 0;
	}

//printf("ans : %d\n", ans);

//for(int i = 1; i<=N; ++i){
//	printf("%d ", visited[i]);
//}


	for(int i = 1; i<=N; ++i){
		flag = 0;
		if(visited[i]==0){
			visited[i] = 1;
			for(int j = 1; j<=N; ++j){
				if(arr[i][j]==1 && visited[j]==0){
					DFS(arr, visited, j, N);
					flag = 1;
				}
			}
			//printf("iiiiii = %d\n", i);
			if(flag==1)
				++ans;
		}
	}

//printf("ans : %d\n", ans);
//for(int i = 1; i<=N; ++i){
//	printf("%d ", visited[i]);
//}
//printf("\n");
//for(int i = 1; i<=N; ++i){
//	printf("%d ", visited[i]);
//}
	printf("%d\n", ans);

	return 0;
}