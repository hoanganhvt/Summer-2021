#include<iostream>
#include<cstring>
using namespace std;
#define MOD 1000000

int N,k;
int memo[110][110];

int solve(int N,int k){
	if(k == 1) return 1;
	if(memo[N][k] != -1) return memo[N][k];
	int cur = 0;
	for(int i = 0; i <= N;i++){
		cur = (cur+solve(N-i,k-1))%MOD;
	}
	return memo[N][k] = cur;
}
int main(){
	while(cin >> N >> k, (N|k)){
		memset(memo,-1,sizeof memo);
		cout << solve(N,k) << endl;
	}
}