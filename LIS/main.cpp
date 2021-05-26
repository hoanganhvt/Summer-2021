#include<iostream>
using namespace std;
int solve(int arr[],int N){
    int maxNum = 1;
    int maxPos = 1;
    int dp[N+1];
    for(int i = 1; i <= N;i++){
        dp[i] = 1;
    }

    for(int i = 1; i <= N;i++){
        for(int j = 1; j < i;j++){
            if(arr[j] > arr[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                maxNum = (dp[i] > maxNum) ? dp[i] : maxNum;
            }
        }
    }

    return maxNum;
}
int main(){
    int N;
    cin >> N;
    int arr[N+1];
    for(int i = 1; i <= N;i++){
        cin >> arr[i];
    }
    cout << solve(arr,N) << endl;
    system("pause");
}