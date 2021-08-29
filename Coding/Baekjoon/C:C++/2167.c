#include <stdio.h>

int main(void)
{
	int N, M, K, i, j, x, y;
	int a[301][301];
	int p, q, r;
	int sum[10001] = {0, };

	scanf("%d%d", &N, &M);
	for(p=0;p<N;++p){
		for(q=0;q<M;++q){
			scanf("%d", &a[p][q]);
		}
	}
	scanf("%d", &K);
	for(p=0;p<K;++p){
		scanf("%d%d%d%d", &i, &j, &x, &y);
		i--; j--; x--; y--;
		
		for(q=i;q<=x;++q){
			for(r=j;r<=y;++r){
				sum[p] += a[q][r];
			}
		}
	}	
	for(p=0;p<K;++p){
		printf("%d\n", sum[p]);
	}
	return 0;
}

/*
1 2 4
8 16 32

N 2 M 3
(1,1) map[1][1] = 1
(1,2) map[1][2] = 1+2
(1,3) map[1][3] = 1+2+4
map[1][m] = map[1][m]+map[0][m]
		  == map[1][m]

(2,1) map[2][1] = 8
(2,2) map[2][2] = 8+16
(2,3) map[2][3] = 8+16+32
map[2][m] = map[2][m]+map[1][m]
		  == map[1][m]+map[2][m]
(2,1) map[2][1] = 1 + 8
(2,2) map[2][2] = 1+2 + 8+16
(2,3) map[2][3] = 1+2+4 + 8+16+32

map[2][3]
1*3 2*2 4*1
8*3 16*2 32*1



*/