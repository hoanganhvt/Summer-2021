#include<iostream>
using namespace std;

int solve(int N){
	int dp[N+1][N+1];
	dp[0][0] = 1;
	for(int i = 1; i <= N;i++){
		dp[i][0] = 1;
		dp[i][1] = 1;
		for(int j = 2; j <= i;j++){
			int joined = (i-1 >= j) ? dp[i-1][j]*j : 0;
			int nojoined =  dp[i-1][j-1];
			dp[i][j] = joined + nojoined;
			dp[i][0] += dp[i][j];
		}
	}
	return dp[N][0];
}
int main(){
	int N;
	cin >> N;
	cout << solve(N) << endl;
	system("pause");
}