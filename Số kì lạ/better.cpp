#include<iostream>
#include<cstdio>
using namespace std;
 
#define maxMod 100
 
int dp[10001][101][2];
 
int main(){
	string k;
	cin >> k;
	int d;
	cin >> d;
	dp[0][0][0] = 1;
	int res = 0;
	for(int i = 0; i < k.length();i++){
		for(int j = 0; j <= d;j++){
			if(dp[i][j][0]+dp[i][j][1] != 0){
				for(int digit = 0; digit <= 9;digit++){
					if((k[i]-'0') < digit){
						dp[i+1][(digit%d+j)%d][1] += dp[i][j][1];
					}
					if((k[i]-'0') > digit){
						dp[i+1][(digit%d+j)%d][1] += (dp[i][j][0]+dp[i][j][1]);
					}
					if((k[i]-'0') == digit){
						dp[i+1][(digit%d+j)%d][0] += dp[i][j][0];
						dp[i+1][(digit%d+j)%d][1] += dp[i][j][1];
					}
				}
			}
		}
	}
	cout << dp[k.length()][0][0]+dp[k.length()][0][1]-1 << endl;
}
 