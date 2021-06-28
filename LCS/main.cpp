#include<iostream>
#include<string>
using namespace std;

int longestCommonSubtring(string myStr1,string myStr2){
	int dp[myStr1.length()+1][myStr2.length()+1];

	for(int i = 0; i <= myStr1.length();i++){
		for(int j = 0; j <= myStr2.length();j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
				continue;
			}
			if(myStr1[i-1] == myStr1[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
				continue;
			}
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

		}
	}
	return dp[myStr1.length()][myStr2.length()];
	
}
int main(){
	string str1,str2;
	cin >> str1 >> str2;
	cout << longestCommonSubtring(str1,str2) << endl;
	system("pause");
}