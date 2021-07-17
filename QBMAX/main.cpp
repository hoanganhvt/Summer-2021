#include<iostream>
using namespace std;
#define inf 2147483647
int solve(int M,int N,int arr[][100]){
	int dp[M][N];
	int result;
	for(int n = 0; n < N;n++){
		int maxVal = -inf;
		for(int m = 0; m < M;m++){
			if(n == 0){
				dp[m][n] = arr[m][n];
			}
			else{
				int backup = (m-1 >= 0) ? dp[m-1][n-1]:-inf;
				int backdown = (m+1 < M) ? dp[m+1][n-1]:-inf;
				int back = dp[m][n-1];
				dp[m][n] = max(max(backup,backdown),back)+arr[m][n];
			}
			maxVal = max(maxVal,dp[m][n]);
			if(m == M-1 && n == N-1){
				result = maxVal;
			}
		}
	}
	return result;
}
int main(){
	int M,N;
	cin >> M >> N;
	int arr[M][100];
	for(int i = 0; i < M;i++){
		for(int j = 0; j < N;j++){
			cin >> arr[i][j];
		}
	}
	cout << solve(M,N,arr) << endl;
	system("pause");
}