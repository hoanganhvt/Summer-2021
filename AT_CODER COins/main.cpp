#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<iomanip>
using namespace std;
int main(){
	int N;
	cin >> N;
	float P[N+1];
	for(int i = 1; i <= N;i++){
		cin >> P[i];
	}
	float dp[N+1][N+1];
	memset(dp,0,sizeof(dp[0][0])*(N+1)*(N+1));
	dp[1][1] = P[1];
	dp[1][0] = (1.0-P[1]);
	for(int i = 2; i <= N;i++){
		for(int j = 0; j <= N;j++){
			float cool = (j > 0) ? dp[i-1][j-1]*P[i] : 0;
			float uncool = dp[i-1][j]*(1.0-P[i]);
			dp[i][j]= cool+uncool;
		}
	}

	float cnt = 0;
	for(int i = N/2+1; i <= N;i++){
		cnt+= dp[N][i];
	}
	cout << fixed << setprecision(10) << cnt << endl;
	system("pause");
}