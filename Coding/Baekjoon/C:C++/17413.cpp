#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define MAX 100001

queue<char> answer;
stack<char> temp;

void reverse(char S[]){
	bool in_tag = false;

	for(int i = 0; S[i]!='\0'; ++i){
		if(S[i]=='<' || in_tag==true){
			if(S[i]=='>'){
				answer.push(S[i]);
				in_tag = false;
				continue;
			}
			answer.push(S[i]);
			in_tag = true;
			continue;
		}
		else if((S[i]>='a' && S[i]<='z') || (S[i]>='0' && S[i]<='9') || S[i]==' ' || S[i+1]=='\0' || S[i+1]=='<'){
			if(S[i]==' '){
				while(temp.empty()==false){
					char top = temp.top();
					answer.push(top);
					temp.pop();
				}
				answer.push(' ');
				continue;
			}
			else if(S[i+1]=='\0' || S[i+1]=='<'){
				temp.push(S[i]);
				while(temp.empty()==false){
					char top = temp.top();
					answer.push(top);
					temp.pop();
				}
				continue;
			}
			temp.push(S[i]);
			continue;
		}
	}
}

int main(){
	char S[MAX] = {0, };

	cin.getline(S, MAX, '\n');

	reverse(S);

	while(answer.empty()==false){
		char front = answer.front();
		cout << front;
		answer.pop();
	}cout << endl;

	return 0;
}