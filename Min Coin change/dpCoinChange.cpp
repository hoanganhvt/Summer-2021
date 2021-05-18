#include<iostream>
using namespace std;
const int inf = 10000000;
void inDay(int arr[],int N){
    for(int i = 0; i < N;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int minCoin(int Coins[],int S,int N){
    int dp[S+1];
    dp[0] = 0;
    for(int i = 1; i <= S;i++){
        dp[i] = inf;
        for(int j = 0; j < N;j++){
            if(i-Coins[j] >= 0){
                int tmp = dp[i-Coins[j]];
                if(tmp+1 < inf && tmp+1 < dp[i]){
                    dp[i] = tmp+1;
                }
            }
        }
    }
    inDay(dp,S+1);
    int returnVal = (dp[S] < inf) ? dp[S] : -1;
    return returnVal;
}
int main(){
    int coins[2] = {12,6};
    cout << minCoin(coins,25,2) << endl;
}