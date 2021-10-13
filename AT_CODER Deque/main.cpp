#include<iostream>
#include<algorithm>

using namespace std;
long long dp[3001][3001];
int main(){
	int N;
	cin >> N;
	int arr[N+1];
	for(int i = 1; i <= N;i++){
		cin >> arr[i];
		dp[i][i] = arr[i];
	}

	for(int i = 1; i <= N-1;i++){
		for(int j = 1;i+j <= N;j++){
			dp[j][i+j] = max(arr[j]-dp[j+1][i+j],arr[i+j]-dp[j][i+j-1]);
		}
	}
	cout << dp[1][N] << endl;
	system("pause");
}