#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int dp[1001];
int arr[11][1001];
int pos[11][1001];
int m,N;
bool isGood(int past,int present){
	for(int i = 2; i <= m;i++){
		int a = pos[m][past];
		int b = pos[m][present];
		if(pos[i][past]  > pos[i][present]){
			return false;
		}
	}
	return true;
}
int main(){
	int res = 0;
	cin >> N >> m;
	for(int i = 1;i <= m;i++){
		for(int j = 1; j <= N;j++){
			cin >> arr[i][j];
			pos[i][arr[i][j]] = j;
		}
	}
	for(int i = 1;i <= N;i++){
		for(int j = 1; j < i;j++){
			if(isGood(arr[1][j],arr[1][i])){
				dp[arr[1][i]] = max(dp[arr[1][i]],dp[arr[1][j]]+1);
				res = max(res,dp[arr[1][i]]);
			}
		}
	}
	cout << res+1 << endl;
}
