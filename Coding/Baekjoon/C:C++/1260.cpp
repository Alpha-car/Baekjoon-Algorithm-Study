#include <iostream>
#include <queue>
using namespace std;
#define MAX 1001

void clear(int visited[], int N){
	for(int i = 0; i<=N; ++i){
		visited[i] = 0;
	}
}

void DFS(int V, int N, int arr[][MAX], int visited[]){
	printf("%d ", V); 
	visited[V] = 1;
	for(int i = 1; i<=N; ++i){
		if(arr[V][i]==1 && visited[i]==0)
			DFS(i, N, arr, visited);
	}
}

void BFS(int V, int N, int arr[][MAX], int visited[]){
	queue<int> q;
	q.push(V);
	visited[V] = 1;
	for(int i = 1; i<=N; ++i){
		if(arr[V][i]==1 && visited[i]==0){
			q.push(i);
			visited[i] = 1;
		}
	}
	while(!q.empty()){
		int size = q.size();
		for(int i = 0; i<size; ++i){
			printf("%d ", q.front());
			q.pop();
			V = q.front();
			//printf("V : %d\n", V);
			for(int j = 1; j<=N; ++j){
				if(arr[V][j]==1 && visited[j]==0){
					q.push(j);
					visited[j] = 1;
				}
			}
		}
	}
}

int main(){
	int N, M, V;
	cin >> N >> M >> V;

	int arr[MAX][MAX] = {0, };
	int visited[MAX] = {0, };
	int src, dst;
	for(int i = 0; i<M; ++i){
		cin >> src >> dst;

		arr[src][dst] = 1;
		arr[dst][src] = 1;
	}
/*
for(int i = 0; i<=N; ++i){
	for(int j = 0; j<=N; ++j){
		printf("%d ", arr[i][j]);
	}
	printf("\n");
}*/

	DFS(V, N, arr, visited);
	printf("\n");
	clear(visited, N);
	BFS(V, N, arr, visited);
	printf("\n");

	return 0;
}