#include <stdio.h>
#define MAX 10001

int d(int n)
{
	int output = 0;
	output += n;
	while(n!=0){
		output += n%10;
		n = n/10;
	}
	return output;
}

void Depth(int src, int visited[MAX])
{
	if(src>=MAX){
		return ;
	}

	visited[src] = 1;
	src = d(src);
	Depth(src, visited);
}

int main(void)
{
	int visited[MAX] = {0, };


	for(int i = 1; i<MAX; ++i){
		if(visited[i]==0){
			Depth(i, visited);
			printf("%d\n", i);
		}
	}
	return 0;
}