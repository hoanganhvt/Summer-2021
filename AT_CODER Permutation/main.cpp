#include<iostream>

#define MOD 1000000007

using namespace std;

int dp[3001][3001];
int add(int i, int j) {
	if ((i += j) >= MOD)
		i -= MOD;
	return i;
}

int sub(int i, int j) {
	if ((i -= j) < 0)
		i += MOD;
	return i;
}

int main(){
	int N;
	cin >> N;
	dp[1][1] = 1;
	for(int i = 2; i <= N;i++){
		 char ch;
		 cin >> ch;
		 for(int j = 1; j <= i;j++){
			 if(ch == '<'){
				 dp[i][j] = add(dp[i][j-1],dp[i-1][j-1]);
			 }
			 if(ch == '>'){
				 dp[i][j] = add(dp[i][j-1],sub(dp[i-1][i-1],dp[i-1][j-1]));
			 }
		 }
	}
	cout << dp[N][N] << endl;
}