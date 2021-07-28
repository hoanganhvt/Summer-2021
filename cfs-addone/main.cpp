#include<iostream>
#include<sstream>
#include<cstring>
using namespace std;

#define base 1000000007
const int maxN = 200005;

int main(){
	int t;
	int dp[maxN];
	for(int i = 0; i <= 8;i++){
		dp[i] = 2;
	}
	dp[9] = 3;
	for(int i = 10; i < maxN;i++){
		dp[i] = (dp[i-9]+dp[i-10])%base;
	}
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while(t--){
		int N,m;
		cin >> N >> m;
		int ans = 0;
		while(N > 0){
			int x = N%10;
			ans += ((x+m <10) ? 1 : (dp[x+m-10])%base);
			ans %= base;
			N = N/10;
		}
		cout  << ans << endl;
	}
}