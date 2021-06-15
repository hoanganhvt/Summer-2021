#include<iostream>
using namespace std;

struct stuff{
    int weight;
    int val;
    int quan;
};
stuff arr[10000];
int N,W0;
int W,S,maxSum = 0;
void Try(int i){
    for(int j = 0; j <= arr[i].quan;j++ ){
        if(W + arr[i].weight*j <= W0){
            S += arr[i].val*j;
            W += arr[i].weight*j;
            if(S > maxSum){
                maxSum = S;
            }
            if(i < N){
                Try(i+1);
            }
            S -= arr[i].val*j;
            W -= arr[i].weight*j;
        }
    }
}
int main(){
    cin >> N >> W0;
    for(int i = 1; i <= N;i++){
        cin >> arr[i].weight;
        cin >> arr[i].val;
        cin >> arr[i].quan;
    }
    Try(1);
    cout << maxSum << endl;
    system("pause");
}