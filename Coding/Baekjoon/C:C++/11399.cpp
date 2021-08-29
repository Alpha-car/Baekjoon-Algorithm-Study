#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX 1001

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if(num1 < num2)
		return -1;
	if(num1 > num2)
		return 1;
	return 0;
}

int main()
{
	int N;
	int arr[MAX] = {0, };
	
	cin >> N;

	for(int i = 0; i<N; ++i){
		cin >> arr[i];
	}

	qsort(arr, N, sizeof(int), compare);

	int time[MAX] = {0, };
	int tmp = 0;

	for(int i = 0; i<N; ++i){
		tmp += arr[i];

		time[i] = tmp;
	}
//	printf("tmp : %d\n", tmp);
	int sum = 0;
	for(int i = 0; i<N; ++i){
		sum += time[i];
	}

	cout << sum << endl;
	return 0;
}