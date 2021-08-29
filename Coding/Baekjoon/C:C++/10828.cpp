#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


queue<int> q;

void opr_push(int X){
	q.push(X);
}

void opr_pop(){
	if(q.empty()==true){
		cout << -1 << endl;
		return ;
	}

	queue<int> tmp;
	
	int size = q.size();

	for(int i = 0; i<size-1; ++i){
		tmp.push(q.front());
		q.pop();
	}
	cout << q.front() << endl;
	q.pop();
	while(!(tmp.empty()==true)){
		q.push(tmp.front());
		tmp.pop();
	}
}

void opr_size(){
	cout << q.size() << endl;
}

void opr_empty(){
	if(q.empty()==true)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}

void opr_top(){
	if(q.empty()==true)
		cout << -1 << endl;
	else
		cout << q.back() << endl;
}

int main(){

	int X;
	char opr[6] = {0, };

	int N;
	cin >> N;
	for(int i = 0; i<N; ++i){
		scanf("%s", opr);
		if(!strcmp(opr, "push")){
			scanf("%d", &X);
			opr_push(X);
		}
		if(!strcmp(opr, "pop"))
			opr_pop();
		if(!strcmp(opr, "size"))
			opr_size();
		if(!strcmp(opr, "empty"))
			opr_empty();
		if(!strcmp(opr, "top"))
			opr_top();
	}

	return 0;
}