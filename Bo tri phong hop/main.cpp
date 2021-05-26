#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct workTime{
    int start;
    int end;
};

bool mySortType(workTime a,workTime b){
    return a.start <= b.start;
}

int solve(vector<workTime>workArr){
    int maxNum;
    sort(workArr.begin(),workArr.end(),mySortType);
    int dp[workArr.size()];
    for(int i = 0; i < workArr.size();i++){
        dp[i] = 1;
    }

    for(int i = 1; i <= workArr.size();i++){
        for(int j = 0; j < i;j++){
            if(workArr[j].start >= workArr[i].start && dp[j] + 1 >= dp[i]){
                dp[i] = dp[j] + 1;
                maxNum = (dp[i] > maxNum) ? dp[i] : maxNum;
            }
        }
    }
    return maxNum;
}
int main(){
    int N;
    cin >> N;
    vector<workTime>workArr;
    for(int i = 0; i < N;i++){
        workTime tmp;
        cin >> tmp.start;
        cin >> tmp.end;
        workArr.push_back(tmp);
    }
    cout << solve(workArr) << endl;
    system("pause");
}