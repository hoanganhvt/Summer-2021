#include<iostream>
using namespace std;
int arr[10000];


bool solve(int S,int i){
    if(S == 0){
        return true;
    }
    if(i == 0){
        return false;
    }

    bool include = (arr[i-1] <= S) ? solve(S-arr[i-1],i-1) : false;
    bool exclude = solve(S,i-1);
    return (include || exclude);
}
int main(){
    int N,S;
    cin >> N >> S;
    for(int i = 0; i < N;i++){
        cin >> arr[i];
    }
    cout << solve(S,N) << endl;
    system("pause");
}