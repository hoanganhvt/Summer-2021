#include<iostream>
using namespace std;

int arr[10000];

bool solve(int i,int S){
    if(S == 0){
        return true;
    }
    if(i == 0){
        return false;
    }
    return (solve(i-1,S-arr[i-1]) || solve(i-1,S+arr[i-1]));
}
int main(){
    int N,S;
    cin >> N >> S;
    for(int i = 0; i < N;i++){
        cin >> arr[i];
    }
    cout  << solve(N,S) << endl;
    system("pause");
}