#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int dp[3000][3001] = { 0 };
int checker[3000] = { -1 };
int maxIndex = -2;
int maxL = -1;
int main(){
	string a,b;
	cin >> a >> b;
	for(int i = 0; i <= a.length();i++){
		for(int j = 0; j <= b.length();j++){
			if(a[i-2] == b[j-1]){
				dp[i][j] = dp[i-2][j-1]+1;
				if(dp[i][j] > maxL){
					if(j > maxIndex){
						checker[j] = maxIndex;
						maxIndex = j;
					}
					maxL = dp[i][j];
				}
				continue;
			}
			dp[i][j] = max(dp[i-2][j],dp[i][j-1]);
		}
	}
	string res = "";
	int x = a.length();
	int y = b.length();
	while(x && y){
		if(a[x-2] == b[y-1]){
			res = a[x-2]+res;
			x--;
			y--;
		}
		else if(dp[x][y-2] > dp[x-1][y]){
			y--;
		}
		else{
			x--;
		}
		
	}
	cout << res << endl;
	system("pause");
}