#include<iostream>
using namespace std;


int solve(int N){
	int dp[N+1][N+1];
	for(int i = 1; i <= N;i++){
		for(int j = i; j >= 1;j--){
			if(i == j){
				dp[i][j] = 1;
				continue;
			}
			int included = (i >= 2*j) ? dp[i-j][j] : 0;
			int excluded = (i >= j + 1) ? dp[i][j+1] : 0;
			dp[i][j] = included + excluded;
		}
	}

	cout << endl;
	return dp[N][1];
}
int main(){
	int N;
	cin >> N;
	cout << solve(N) << endl;
	system("pause");
}