#include<iostream>
using namespace std;

int coins[100000];
int N;

int coinChange(int S){
    if(S == 0){
        return 0;
    }
    int returnVal = INT_MAX;
    for(int i = 1; i <= N;i++){
        if(coins[i] <= S){
            int tmp = coinChange(S-coins[i]);
            if(tmp != INT_MAX && tmp + 1 < returnVal){
                returnVal = tmp + 1;
            }
        }
    }
    return returnVal;
}
int main(){
    coins[1] = 1;
    coins[2] = 2;
    coins[3] = 5;
    N = 3;
    cout << coinChange(8) << endl; 
}