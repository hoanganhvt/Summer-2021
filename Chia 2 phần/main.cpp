#include<iostream>
#include<cmath>
using namespace std;

int solve(int arr[],int N,int S){
    int maxSum = 1000000000;
    int minNum = 0;

    int dp[S];
    dp[0] = 1;
    for(int i = 0; i < N;i++){
        for(int s = S-1;s >= arr[i];s--){
            if(dp[s-arr[i]] == 1){
                dp[s] = 1;
                int tmp = abs(2*s-S);
                if(tmp < maxSum){
                    maxSum = tmp;
                    minNum = s;
                }
            }
        }
    }

    return minNum;
}
int main(){
    int N,S = 0;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N;i++){
        cin >> arr[i];
        S += arr[i];
    }
    cout << solve(arr,N,S) << endl;
    system("pause");
}