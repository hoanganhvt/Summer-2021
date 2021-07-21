#include<iostream>
using namespace std;

int solve(int arr[],int N){
	int dp[N+1];
	int maxL = 1;
	for(int i = 1; i <= N;i++){
		dp[i] = 1;
	}

	for(int i = 2; i <= N;i++){
		for(int j = 1; j < i;j++){
			if(arr[i] > arr[j]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		maxL = max(maxL,dp[i]);
	}
	return maxL;
}
int main(){
	int N;
	int arr[10000];
	cin >> N;
	for(int i = 1; i <= N;i++){
		cin >> arr[i];
	}
	cout << solve(arr,N) << endl;
	system("pause");
}