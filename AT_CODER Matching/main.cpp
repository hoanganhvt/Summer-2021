#include<iostream>
using namespace std;
int dp[1<<21] = { 0 };
#define mod 1000000007
int main(){
	dp[0] = 1;
	int N;
	cin >> N;
	int arr[N][N];
	for(int i = 0; i < N;i++){
		for(int j = 0; j < N;j++){
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i < (1<<N);i++){
		int ith = __builtin_popcount(i);
		for(int bit = 0;bit < N;bit++){
			if(!arr[ith][bit] || ((1<<bit) & i)){
				continue;
			}
			dp[(1 << bit) | i] = (dp[(1 << bit) | i] + dp[i])%mod;
		}
	}
	cout << dp[(1 << N)-1] << endl;
	system("pause");
}