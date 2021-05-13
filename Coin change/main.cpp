#include<iostream>
using namespace std;

int coins[10000];

int coinChange(int S,int i){
    if(S == 0){
        return 1;
    }
    if(i == 0){
        return 0;
    }
    if(coins[i] > S){
        return coinChange(S,i-1);
    }
    return coinChange(S,i-1) + coinChange(S-coins[i],i);
}


int main(){
    int N,S;
    cin >> S >> N;
    for(int i = 1; i <= N;i++){
        cin >> coins[i];
    }
    cout << coinChange(S,N) << endl;
}