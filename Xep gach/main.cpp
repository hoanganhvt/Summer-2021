#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct brick{
    int length;
    int width;
    int height;
};

bool mySortType(brick br1,brick br2){
    return br1.width <= br1.width;
}
int solve(vector<brick>arr){
    int maxNum;
    sort(arr.begin(),arr.end(),mySortType);
    int dp[arr.size()];

    for(int i = 0;i < arr.size();i++){
        dp[i] = 1;
    }
    for(int i = 1; i < arr.size();i++){
        for(int j = 0; j < i;j++){
            if(arr[j].length < arr[i].length && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
                if(dp[i] > maxNum){
                    maxNum = dp[i];
                }
            }
        }
    }
    return maxNum;
}
int main(){
    vector<brick>arr;
    int N;
    cin >> N;
    for(int i = 0; i < N;i++){
        brick tmp;
        cin >> tmp.height >> tmp.length >> tmp.width;
        arr.push_back(tmp);
    }
    cout << solve(arr) << endl;
    system("pause");
}