#include<iostream>
#include<algorithm>
using namespace std;
int Weight[10000];
int Value[10000];
int solve(int w,int i){
    if(Weight[i] > w){
        return 0;
    }
    else if(i == 0){
        return 0;
    }
    return max(solve(w-Weight[i],i-1)+Value[i],solve(w,i-1)); 
}
int main(){
    int N,W;
    cin >> W >> N;
    for(int i = 1; i <= N;i++){
        cin >> Weight[i] >> Value[i];
    }
    cout << solve(W,N) << endl;
    system("pause");
}