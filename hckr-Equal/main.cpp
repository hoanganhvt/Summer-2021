#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        int minVal = INT_MAX;
        int arr[N];
        for(int i = 0; i < N;i++){
            cin >> arr[i];
            minVal = min(minVal,arr[i]);
        }
        int ans = INT_MAX;
        for(int d = minVal-4; d <= minVal;d++){
            int res = 0;
            for(int i = 0; i < N;i++){
            int x = arr[i]-d;
            res += x/5, x%=5;
            res += x/2, x%=2;
            res += x;
            }
            ans = min(res,ans);
        }
        cout << ans << endl;
    }
}
