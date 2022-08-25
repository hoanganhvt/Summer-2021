#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define S 0
#define E 1

struct stuff{
	int num;
	int property;
	int index;
};


bool mySortType(stuff a,stuff b){
	return (a.num < b.num);
}
int dp[400000];
int main(){
	int n;
	cin >> n;
	vector<stuff>arr;
	for(int i = 0;i < n;i++){
		stuff tmp;
		int a,b;
		cin >> a >> b;
		tmp = {a,0,i};
		arr.push_back(tmp);
		tmp = {b,1,i};
		arr.push_back(tmp);
	}
	sort(arr.begin(),arr.end(),mySortType);
	int res = 0;
	for(int i = 1; i < arr.size();i++){
		if(arr[i].property == E){
			dp[arr[i].index] = 1;
		}
		if(arr[i].property == S && arr[i-1].property == E){
			dp[arr[i].index] = max(dp[arr[i].index],dp[arr[i-1].index]+1);
		}
		res = max(res,dp[arr[i].index]);
	}
	cout << res << endl;
	system("pause");
}