#include<iostream>

using namespace std;
#define maxS 90000

int dp[1000][maxS][2];

int main(){
	string K;
	int D;
	cin >> K >> D;
	long long res = 0;
	for(int i = 0; i < K.length();i++){
		for(int j = 0; j <= 9*(i+1);j++){
			for(int digit = 0;digit <= 9;digit++){
				if(i == 0){
					if(digit < (K[0]-'0')){
						dp[i][digit][1] = 1;
					}
					if(digit == (K[0]-'0')){
						dp[i][digit][0] = 1;
					}
					continue;
				}
				if(j == 0){
					dp[i][j][1] = 1;
					continue;
				}
				if(digit < (K[i]-'0')){
					dp[i][j][1] += dp[i-1][j-digit][0];
					dp[i][j][1] += dp[i-1][j-digit][1];
					continue;
				}
				if(digit > (K[i]-'0')){
					dp[i][j][1] += dp[i-1][j-digit][1];
					continue;
				}
				if(digit == (K[i]-'0')){
					dp[i][j][0] += dp[i-1][j-digit][0];
					continue;
				}
			}
			if((i == K.length()-1 && dp[i][j][0]+dp[i][j][1] != 0) && j % D == 0){
				res += (dp[i][j][0]+dp[i][j][1]);
			}
		}
	}
	cout << res-1 << endl;
}
