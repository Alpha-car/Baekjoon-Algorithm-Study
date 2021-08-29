#include <iostream>
#include <queue>
using namespace std;
#define MAX 51

int min(int a, int b){
	if(a>b)
		return b;
	return a;
}

void Print(int N, int M, int arr[][MAX]){
	for(int i = 0; i<N; ++i){
		for(int j = 0; j<M; ++j){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int square_area(int hdr, int N, int M, int hx, int hy, int arr[][MAX]){
	queue< pair<int, int> > q;
	int num = min(N-hx, M-hy);

	for(int i = num-1; i>=0; --i){
		q.push({i,i});
	}

	int plus_x, plus_y;

	//printf("????\n");	
	while(!q.empty()){
		plus_x = q.front().first;
		plus_y = q.front().second;
		q.pop();

		//printf("hdr : %d // num : %d\n arr[%d][%d]\n", hdr, num, cur_x, cur_y);
		if(arr[hx+plus_x][hy+plus_y]==hdr && arr[hx+plus_x][hy]==hdr && arr[hx][hy+plus_y]==hdr)
			break;

	}

	return (plus_x+1)*(plus_y+1);
}

int main(){

	int arr[MAX][MAX] = {0, };
	int visited[10] = {0, };

	int N, M;
	cin >> N >> M;
	for(int i = 0; i<N; ++i){
		char row[MAX];
		cin >> row;

		for(int j = 0; row[j]!='\0'; ++j){
			arr[i][j] = row[j]-'0';
		}
	}

//Print(N, M, arr);

	int area[10] = {0, };

	for(int i = 0; i<N; ++i){
		for(int j = 0; j<M; ++j){
			int hdr = arr[i][j];
			if(visited[hdr]==0){
				if(area[hdr]<square_area(hdr, N, M, i, j, arr))
					area[hdr] = square_area(hdr, N, M, i, j, arr);
				//printf("area : %d\n", area[hdr]);
			}
		}
	}

	int ans = 0;

	for(int i = 0; i<10; ++i){
		//printf("%d ", area[i]);

		if(ans<area[i])
			ans = area[i];
	}

	cout << ans << endl;

	return 0;
}