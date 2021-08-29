#include <stdio.h>

int cnt;

void DFS(int index, int is_visited[], int depth, int h[])
{
	if(depth == 2 && cnt==0){
		int sum = 0;

		for(int i = 0; i<9; ++i){
			if(is_visited[i] == 0)
				sum += h[i];
		}

		if(sum == 100){
			for(int i = 0; i<9; ++i){
				if(is_visited[i] == 0)
					printf("%d ", h[i]);
			}
			printf("\n");
			cnt++;
		}

		return ;
	}
	for(int i = index; i<9; ++i){
		if(is_visited[i]==0){
			is_visited[i] = 1;
			depth++;
			DFS(index++, is_visited, depth, h);
			is_visited[i] = 0;
			depth--;
		}
	}
}

int main(void)
{
	int h[9] = {0, };
	int index = 0;
	int depth = 0;
	int is_visited[9] = {0, };
	int tmp;

	cnt = 0;

	for(int i = 0; i<9 ; ++i){
		scanf("%d", &h[i]);
	}
	for(int i = 0; i<8; ++i){
		for(int j = i+1; j<9; ++j){
			if(h[i]>h[j]){
				tmp = h[i];
				h[i] = h[j];
				h[j] = tmp;
			}
		}
	}

	DFS(index, is_visited, depth++, h);
}