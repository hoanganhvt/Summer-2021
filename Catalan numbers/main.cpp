#include<iostream>
using namespace std;

int solve(int N){
	int dp[N+1];
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= N;i++){
		dp[i] = 0;
		for(int j  = 0; j < i;j++){
			dp[i] += dp[i-j-1]*dp[j];
		}
	}
	return dp[N];
}
int main(){
	int N;
	cin >> N;
	cout << solve(N) << endl;
	system("pause");
}