#include<iostream>
using namespace std;

void inDay(int N,int arr[]){
	for(int i = 0;i < N;i++){
		cout << arr[i];
	}
	cout << endl;
}

void fillVal(int arr[],int start,int end,int val){
	for(int i = start; i <= end;i++){
		arr[i] = val;
	}
}
void gen(int arr[],int N){
	fillVal(arr,0,N-1,0);
	inDay(N,arr);
	int i = N-1;
	while(i >= 0){
		if(arr[i] == 0){
			arr[i] = 1;
			fillVal(arr,i+1,N-1,0);
			inDay(N,arr);
			i = N-1;
		}
		else if(arr[i] == 1){
			i--;
		}
	}
}
int main(){
	int arr[10000];
	gen(arr,5);
	system("pause");
}