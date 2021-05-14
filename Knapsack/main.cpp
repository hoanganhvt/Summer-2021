#include<iostream>
#include<algorithm>
using namespace std;

int knapSack(int Weight[],int Value[],int N,int Wt){
    int dp[Wt+1][N+1];
    for(int w = 0; w <= Wt;w++){
        for(int i = 0;i <= N;i++){
            if(w == 0 || i == 0){
                dp[w][i] = 0;
            }
            else if(Weight[i] > w){
                dp[w][i] = 0;
            }
            else{
                dp[w][i] = max(dp[w][i-1],dp[w-Weight[i]][i-1]+Value[i]);
            }
        }
    }
    return dp[Wt][N];
}
int main(){

}