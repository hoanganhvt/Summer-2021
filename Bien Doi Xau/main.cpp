#include<iostream>
#include<string>
using namespace std;


int solve(string str1,string str2){
    int dp[str1.length()][str2.length()];

    //i => j

    for(int i = 0; i <= str1.length();i++){
        for(int j = 0; j <= str2.length();j++){
            if(i == 0){
                dp[i][j] = j;
                continue;
            }
            if(j == 0){
                dp[i][j] = i;
                continue;
            }

            if(str1[i] == str2[j]){
                dp[i][j] = dp[i-1][j-1];
                continue;
            }

            int add = dp[i][j-1] + 1;
            int Min = add;
            int del = dp[i-1][j] + 1;
            Min = min(Min,del);
            int rep = dp[i-1][j-1] + 1;
            dp[i][j] = min(Min,rep);
        }
    }
    return dp[str1.length()][str2.length()];
}
int main(){
    string str1,str2;
    cin >> str1 >> str2;
    cout << solve(str1,str2) << endl;
    system("pause");
}