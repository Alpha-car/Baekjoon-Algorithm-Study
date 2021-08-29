#include <iostream>
using namespace std;
#define MAX 101

int N, A, B;
bool relation[MAX][MAX];
bool checked[MAX];
bool valid;
int ans;
/*
void testprint(){
	for(int i = 1; i<=N; ++i){
		for(int j = 1; j<=N; ++j){
			printf("%d ", relation[i][j]);
		}
		printf("\n");
	}
}*/

void relation_count(int src, int dst, int cnt){
	if(src == dst){
		valid = true;
	}

	for(int i = 1; i<MAX; ++i){
		if((relation[src][i]==true || relation[i][src]==true) && checked[i]==false){
			if(i == dst){					
				ans = cnt+1;
				valid = true;

				return ;
			}
			++cnt;
			checked[i] = true;
			relation_count(i, dst, cnt);
			--cnt;
			checked[i] = false;
		}
	}

	if(valid == false)
		ans = -1;
	
	return ;
}	

int main(){

	cin >> N;
	cin >> A >> B;

	int m;
	cin >> m;
	for(int i = 0; i<m; ++i){
		int x, y;
		cin >> x >> y;

		relation[x][y] = true;
	}
//testprint();

	checked[A] = true;
	relation_count(A, B, 0);

	cout << ans << endl;

	return 0;
}