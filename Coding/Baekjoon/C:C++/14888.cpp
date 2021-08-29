#include <iostream>
#include <vector>
using namespace std;
#define MAX 12

int arr[MAX];
bool opr_vst[MAX];
int N;
int maxi, mini;
int tmp;
vector<char> v;
vector<char> w;


void print(vector<char> a){
	for(int i = 0; a.size(); ++i){
		cout << v[i] << " ";
	} cout << endl;
}


void pls(int next){
	tmp += next;
}
void sub(int next){
	tmp -= next;
}
void mul(int next){
	tmp *= next;
}
void dev(int next){
	tmp /= next;
}


void case_opr(int dpt)
{
	if(dpt == v.size()){
		for(int i = 0; i<v.size(); ++i){
			if(w[i] == '+'){
				pls(arr[i+1]);
			}
			if(w[i] == '-'){
				sub(arr[i+1]);
			}
			if(w[i] == '*'){
				mul(arr[i+1]);
			}
			if(w[i] == '/'){
				dev(arr[i+1]);
			}
//			printf("i : %d, tmp : %d\n", i, tmp);
		}
		if(maxi < tmp)
			maxi = tmp;
		if(mini > tmp)
			mini = tmp;

		tmp = arr[0];
		
		return ;
	}

	for(int i = 0; i<v.size(); ++i){
		if(opr_vst[i] == false){
			opr_vst[i] = true;
			++dpt;
			w.push_back(v[i]);
			case_opr(dpt);
			w.pop_back();
			--dpt;
			opr_vst[i] = false;
		}
	}
}

int main()
{

	cin >> N;

	int opr_num[4] = {0, };
	int dpt = 0;

	maxi = -1000000000;
	mini = 1000000000;

	for(int i = 0; i < N; ++i){
		cin >> arr[i];
	}

	for(int i = 0; i < 4; ++i){
		cin >> opr_num[i];
		for(int j = 0; j<opr_num[i]; ++j){
			if(i == 0)
				v.push_back('+');
			else if(i == 1)
				v.push_back('-');
			else if(i == 2)
				v.push_back('*');
			else if(i == 3)
				v.push_back('/');
		}
	}
	
	tmp = arr[0];
	case_opr(dpt);

	cout << maxi << endl;
	cout << mini << endl;

	return 0;
}
