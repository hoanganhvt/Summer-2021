#include<iostream>
#include<algorrithm>
using namespace std;

int gold[100][100];

int maxGold(int m,int n){
    const int mS = m;
    const int nS = n;
    int goldMine[mS][nS];
    for(int col = n-1; col >= 0;col--){
        for(int row = 0; row < m;row++){
           int right = (col == n-1)? 0 : goldMine[row][col+1];
           int upRight = (col == n-1 || row == 0)? 0 :goldMine[row-1][col+1];
           int downRight = (col == n-1 || row == m-1) ? 0 : goldMine[row+1][col+1];
           goldMine[row][col] = max(right,max(upRight,downRight)) + gold[row][col];
        }
    }

    int maxSum = goldMine[0][0];
    for(int i = 0; i < m;i++){
        maxSum  = max(gold[0][i],maxSum);
    }
    return maxSum;
}
int main(){
}
