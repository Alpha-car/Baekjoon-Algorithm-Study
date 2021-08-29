#include <iostream>
using namespace std;
#define MAX 8

struct cell{
	char type;
	bool UD, LR;
	bool sejoon;
	bool vst;
};
struct mov{
	int x, y;
};


int N, M;
int time_cnt;

cell maze[MAX][MAX];
mov now_location;

void testprint(){
	for(int i = 0; i<N; ++i){

		for(int k = 0; k<3; ++k){

			for(int j = 0; j<M; ++j){
			
				if(k==0 || k==2){
					for(int l = 0; l<3; ++l){
						if(l==0 || l==2){ printf("#"); }
						else if(l==1){ 
							if(maze[i][j].UD==true){ printf(" "); }
							else if(maze[i][j].UD==false){ printf("#"); }
						}
					}
				}
				else if(k==1){
					for(int l = 0; l<3; ++l){
						if(l==0 || l==2){ 
							if(maze[i][j].LR==true){ printf(" "); }
							else if(maze[i][j].LR==false){ printf("#"); }
						}
						else if(l==1){ 
							printf("%d", maze[i][j].sejoon);
						}
					}
				}
			
			}
			printf("\n");
		}
	}
}

void turn(){
	for(int i = 0; i<N; ++i){
		for(int j = 0; j<M; ++j){
			if(maze[i][j].type=='C'){ maze[i][j].type='D'; maze[i][j].UD=false; maze[i][j].LR=true; }
			if(maze[i][j].type=='D'){ maze[i][j].type='C'; maze[i][j].UD=true; maze[i][j].LR=false; }
		}
	}
	++time_cnt;
}

int main(){

	cin >> N >> M;

	for(int i = 0; i<N; ++i){
		string row;
		cin >> row;
		for(int j = 0; j<M; ++j){
			if(row[j]=='A'){ maze[i][j].type='A'; maze[i][j].UD=true; maze[i][j].LR=true; }
			if(row[j]=='B'){ maze[i][j].type='B'; maze[i][j].UD=false; maze[i][j].LR=false; }
			if(row[j]=='C'){ maze[i][j].type='C'; maze[i][j].UD=true; maze[i][j].LR=false; }
			if(row[j]=='D'){ maze[i][j].type='D'; maze[i][j].UD=false; maze[i][j].LR=true; }
		}
	}
	maze[0][0].sejoon = true;
	now_location = {0,0};

	testprint();



	cout << time_cnt << endl;

	return 0;
}
