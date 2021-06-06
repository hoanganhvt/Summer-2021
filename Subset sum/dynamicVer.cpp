#include<iostream>
using namespace std;

int solve(int arr[],int N,int S){
    bool dp[S+1];
    dp[0] = true;
    for(int s = 1; s <= S;s++){
        dp[s] = false;
    }

    for(int i = 0; i < N;i++){
        for(int s = S; s >= arr[i];s--){
            if(dp[s-arr[i]]){
                dp[s] = true;
            }
        }
    }
    return dp[S];
}
int main(){
    int N;
    int arr[5] = {5,1,6,9,7};
    cout << solve(arr,6,6) << endl;
    cout << solve(arr,6,66) << endl;
    system("pause");
}