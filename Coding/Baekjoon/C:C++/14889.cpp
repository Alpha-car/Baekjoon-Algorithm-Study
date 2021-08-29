#include <iostream>
using namespace std;
#define MAX 21
#define HALF 11

int ab_Start, ab_Link;
int ans;
int Start[HALF];
int Link[HALF];


void PRINT(int arr[][MAX], int N){
	for(int i = 1; i<=N; ++i){
		for(int j = 1; j<=N; ++j){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void pairing(int S[][MAX], int N, int depth, int new_visited[], int index){
	if(depth==2){
/*for(int i = 1; i<=N/2; ++i){
	printf("%d ", new_visited[i]);
}printf("\n");*/


		int src_1, dst_1;
		int src_2, dst_2;
		for(int i = 1; i<=N/2; ++i){
			if(new_visited[i]==1){
				src_1 = Start[i];
				src_2 = Link[i];
				break;
			}
		}
		for(int i = N/2; i>=1; --i){
			if(new_visited[i]==1){
				dst_1 = Start[i];
				dst_2 = Link[i];
				break;
			}
		}
//printf("  %d, %d, %d, %d\n", src_1, dst_1, src_2, dst_2);
		ab_Start += S[src_1][dst_1] + S[dst_1][src_1]; 
		ab_Link += S[src_2][dst_2] + S[dst_2][src_2]; 
//printf("	%d+%d, %d+%d\n", S[src_1][dst_1], S[dst_1][src_1], S[src_2][dst_2], S[dst_2][src_2]);

		return ;
	}

	for(int i = index; i<=N/2; ++i){
		if(new_visited[i]==0){
			new_visited[i] = 1;
			pairing(S, N, ++depth, new_visited, i);
			--depth;
			new_visited[i] = 0;
		}
	}
}
/*
void ability(int S[][MAX], int N){

printf("!!\n");
for(int i = 1; i<=N/2; ++i){
	printf("%d!\n", i);
	printf("%d ", Start[i]);
}



}*/

void sort(int S[][MAX], int N, int visited[]){

	ab_Start = 0;
	ab_Link = 0;
	int index = 1;
	int depth = 0;
	int new_visited[HALF] = {0, };

	int j = 1;
	int k = 1;
	for(int i = 1; i<=N; ++i){
		if(visited[i]==1){
			Start[j] = i;
			++j;
		}
		else if(visited[i]==0){
			Link[k] = i;
			++k;
		}
	}

//	ability(S, N);
/*for(int i = 1; i<=N/2; ++i){
	printf("%d ", Start[i]);
}printf("\n");
for(int i = 1; i<=N/2;++i){
	printf("%d ", Link[i]);
}printf("\n");*/

	pairing(S, N, depth, new_visited, index);

	int sub;
	if(ab_Start > ab_Link)
		sub = ab_Start - ab_Link;
	else
		sub = ab_Link - ab_Start;

	if(ans > sub)
		ans = sub;
//printf("ab_Start: %d ab_Link: %d ans : %d\n", ab_Start, ab_Link, ans);
//printf("\n");
}

void brutal(int S[][MAX], int N, int depth, int visited[], int index){
	if(depth == N/2){
		
	/*	for(int i = 1; i<=N; ++i){
			printf("%d ", visited[i]);
		}
		printf("\n");	*/

		sort(S, N, visited);
		return ;
	}

	for(int i = index; i<=N; ++i){
		if(visited[i] == 0){
			visited[i] = 1;
			brutal(S, N, ++depth, visited, i);
			--depth;
			visited[i] = 0;
		}

	}

}

int main(){
	int N;
	int depth = 0;
	int S[MAX][MAX] = {0, };
	int visited[MAX] = {0, };
	ans = 10000;

	cin >> N;
	for(int i = 1; i<=N; ++i){
		for(int j = 1; j<=N; ++j){
			cin >> S[i][j];
		}
	}
//PRINT(S, N);
	int index = 1;

	brutal(S, N, depth, visited, index);

	cout << ans << endl;

	return 0;
}