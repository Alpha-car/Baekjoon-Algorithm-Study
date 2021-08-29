#include <iostream>
#include <ctime>
using namespace std;

struct Node{
	Node* head;
	int data;
	bool robot;
	Node* tail;
};

Node* list;
Node* load_point;
Node* unload_point;

int zero_cnt;


void init(){
	if(list==NULL)
		return ;
	else{
		Node* last_point = list;
		Node* cur = list;

		do{	list = cur->tail;
			delete cur;
			cur = list;
		}while(cur!=last_point && cur!=NULL);
	}
}

void add(int key){
	Node* new_node = new Node;

	new_node->head = NULL;
	new_node->data = key;
	new_node->robot = false;
	new_node->tail = NULL;

	if(list==NULL){
		list = new_node;
	}
	else{
		Node* cur = list;
		cur->head = new_node;
		list = new_node;
		new_node->tail = cur;
	}
}

void bind(){
	load_point->tail = list;
	list->head = load_point;
}

void load(){
	if(load_point->robot == false && load_point->data >= 1){
		load_point->robot = true;
		--load_point->data;
		if(load_point->data == 0)
			++zero_cnt;
	}
}
void unload(){
	if(unload_point->robot == true){
		unload_point->robot = false;
	}
}

void rotate(){
	load_point = list;
	Node* temp_node = unload_point;
	unload_point = temp_node->tail;
	list = load_point->tail;

	unload();
}

void robot_move(int N){
	Node* searching = unload_point->tail;
	
	for(int i = 0; i<N-1; ++i){
		if(searching->robot == true){

			Node* nnode = searching->head;
			if(nnode->robot == false && nnode->data >= 1){
				searching->robot = false;
				nnode->robot = true;
				--nnode->data;
				if(nnode->data == 0)
					++zero_cnt;
			}
		}
		Node* temp_node = searching->tail;
		searching = temp_node;
	}
	unload();
}

int main(){
// clock_t start, end;
// double result;
// start = clock();

	cin.tie();
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	init();

	for(int i = 0; i<2*N; ++i){
		int input_A;
		cin >> input_A;
		add(input_A);
		
		if(i == 0)
			load_point = list;
		if(i == N-1)
			unload_point = list;
	}
	bind();
	
	int step_cnt = 0;
	while(K > zero_cnt){
		++step_cnt;

		rotate();
		robot_move(N);
		load();
	}

	cout << step_cnt << endl;
// end = clock();
// result = (double)(end-start);
// cout << result << endl;
	return 0;
}