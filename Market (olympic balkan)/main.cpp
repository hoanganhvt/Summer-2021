#include<iostream>
using namespace std;

int arr[10000];

int solve(int i,int S){
    if(S == 0){
        return 1;
    }

    if(i == 0){
        return 0;
    }

    int included = (arr[i] <= S) ? solve(i-1,S-arr[i-1]) : 0;
    int excluded = solve(i-1,S);
    return included + excluded;
}
int main(){
    int N,S;
    cin >> N >> S;
    for(int i = 0; i < N;i++){
        cin >> arr[i];
    }
    cout << solve(N,S) << endl;
    system("pause");
}