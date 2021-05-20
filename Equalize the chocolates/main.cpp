#include<iostream>
using namespace std;

int dp[1000000];
int mark[1000000];
int Max = 0;
int Min = INT_MAX;
int S = 0;

void change(){
	int changes[3] = {1,2,5};
	for(int i = 1; i <= (Max-Min);i++){
		dp[i] = i;
		for(int j = 0; j < 3;j++){
			if(changes[j] <= i){
				int tmp = dp[i-changes[j]] + 1;
				if(tmp < dp[i]){
					dp[i] = tmp;
				}
			}
		}
		S += mark[i]*dp[i];
	}
}

int equalChoco(int chocos[],int N){
	for(int i = 0; i < N;i++){
		mark[chocos[i]-Min] += 1;
	}
	change();
	return S;
}
int main(){
	int N;
	cin >> t;
	cin >> N;
	const int Ns = N;
	int arr[Ns];
	for(int i = 0; i < Ns;i++){
		cin >> arr[i];
		if(arr[i] > Max){
			Max = arr[i];
		}
		if(arr[i] < Min){
			Min = arr[i];
		}
	}
	cout << equalChoco(arr,N) << endl;
}