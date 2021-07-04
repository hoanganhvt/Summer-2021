#include<iostream>
using namespace std;
#define inf 2147483647


int arr[10000000];
int S[10000000];
int N;
void init(){
	S[0] = 0;
	for(int i = 1; i <= N;i++){
		cin >> arr[i];
		S[i] = S[i-1] + arr[i];
	}
}

int Sigma(int start,int end){
	return S[end] - S[start-1];
}


int solve(int N,int k){
	int dp[N+1][k+1];
	for(int i = 1; i <= N;i++){
		dp[i][1] = Sigma(1,i);
	}

	for(int j = 1; j <= k;j++){
		dp[1][j] = arr[1];
	}

	for(int i = 2; i <= N;i++){
		for(int j = 2; j <= k;j++){
			int best = inf;
			for(int p = 1; p <= i;p++){
				best = min(best,max(dp[p][j-1],Sigma(p+1,i)));
			}
			dp[i][j] = best;
		}
	}
	return dp[N][k];
}

int main(){
	int k;
	cin >> N >> k;
	init();
	cout << solve(N,k) << endl;
	system("pause");
}