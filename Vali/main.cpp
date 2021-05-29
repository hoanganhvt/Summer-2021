#include<iostream>
#include<algorithm>
using namespace std;

struct stuff{
    int weight;
    int val;
};

int solve(stuff arr[],int N,int Wt){
    int dp[Wt+1][N];
    for(int i = 0; i < N;i++){
        dp[0][i] = 0;
    }

    for(int w = 1; w <= Wt;w++){
        for(int i = 0; i < N;i++){
            int included = (arr[i].weight <= w) ? dp[w-arr[i].weight][i-1] + arr[i].val : 0;
            int excluded = (i >= 1 ) ? dp[w][i-1] : 0;
            dp[w][i] = max(included,excluded);
        }
    }
    return dp[Wt][N-1];
}
int main(){
    int N,Wt;
    cin >> N >> Wt;
    stuff arr[N];

    for(int i = 0; i < N;i++){
        cin >> arr[i].weight >> arr[i].val;
    }
    cout << solve(arr,N,Wt) << endl;
    system("pause");
}