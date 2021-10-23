#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct BLOCK{
	long long weight;
	long long strength;
	long long val;
};


long long dp[20001] = { 0 };

bool mySortType(BLOCK i,BLOCK j){
	return i.weight+i.strength < j.weight+j.strength;
}
int main(){
	int N;
	cin >> N;
	int totalSum = 0;
	BLOCK arr[N];
	for(int i = 0; i < N;i++){
		cin >> arr[i].weight >> arr[i].strength >> arr[i].val;
		totalSum+=arr[i].weight;
	}
	sort(arr,arr+N,mySortType);
	long long maxVal = 0;
	for(int i = 0; i < N;i++){
		for(int j = arr[i].strength; j >= 0;j--){
			int tmp = dp[arr[i].weight+j];
			dp[arr[i].weight+j] = max(dp[arr[i].weight+j],dp[j]+arr[i].val);
			maxVal = max(maxVal,dp[arr[i].weight+j]);
		}
	}
	cout << maxVal << endl;
}