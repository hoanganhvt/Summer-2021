#include<iostream>
using namespace std;

int solve(int arr[],int N){
    int maxNum = 0;
    int dp1[N];
    int dp2[N];

    for(int i = 0; i < N;i++){
        dp1[i] = 1;
        dp2[i] = 0;
    }

    for(int i = 1; i < N;i++){
        int dp2I = N - (i+1);
        for(int j = 0; j < i ;j++){
            int dp2J = N - (j+1);
            if(arr[j] < arr[i] && dp1[j] + 1 > dp1[i]){
                dp1[i] = dp1[j] + 1;
            }

            if(arr[dp2J] < arr[dp2I] && dp2[dp2J] + 1 > dp2[dp2I]){
                dp2[dp2I] = dp2[dp2J] + 1;
            }
        }
        if(dp1[i] + dp2[N - (i+1)] > maxNum){
            maxNum = dp1[i] + dp2[N - (i+1)]; 
        }
    }
    return maxNum;
}
int main(){
    int N;
    cin >> N;
    int arr[N];
    for(int i = 0; i < N;i++){
        cin >> arr[i];
    }
    cout << solve(arr,N) << endl;
    system("pause");
}