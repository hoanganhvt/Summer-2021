#include<iostream>
using namespace std;

void solve(int N){
    int dp[6*N+1][N+1];
    for(int S = 1; S <= 6*N;S++){
        for(int i = 1; i <= N;i++){
            dp[S][i] = 0;
        }
    }
    for(int i = 1; i <= N;i++){
        for(int S = i; S <= 6*i;S++){
            if(i == 1 || S == i){
                dp[S][i] = 1;
            }
            else{
                for(int j = 1; j <= 6 && j < S;j++){
                    dp[S][i] += dp[S-j][i-1];
                }
            }
        }
    }

    for(int S = 1; S <= 6*N;S++){
        cout << dp[S][N] << endl;
    }
}
int main(){
    int N;
    cin >> N;
    solve(N);
    system("pause");

}