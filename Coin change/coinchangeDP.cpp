#include<iostream>
using namespace std;

long int included,excluded;

long int coinChange(int coins[],int N,int S){
	long int dp[S+1][N];
	for(int i = 0; i < N;i++){
		dp[0][i] = 1;
	}
	for(int val = 1; val <= S;val++){
		for(int i = 0; i < N;i++){
			included = (val-coins[i] >= 0) ? dp[val-coins[i]][i] : 0;
			excluded = (i >= 1) ? dp[val][i-1] : 0;
			dp[val][i] = included + excluded;
		}		
	}
	return dp[S][N-1];
}
int main(){
	int N,S;
	cin >> S >> N;
	int coins[N];
	for(int i = 0; i < N;i++){
		cin >> coins[i];
	}
	cout << coinChange(coins,N,S) << endl;
}