#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct stuff{
	int weight;
	int val;
};

int solve(vector<stuff>arr,int W){
	int maxVal = 0;
	int dp[W+1];
	dp[0] = 0;
	for(int i = 1; i <= W;i++){
		dp[i] = -1;
	}

	for(int i = 0; i < arr.size();i++){
		for(int w = W;w >= arr[i].weight;w--){
			if(dp[w-arr[i].weight] != -1 && dp[w-arr[i].weight] + arr[i].val > dp[w]){
				dp[w] = dp[w-arr[i].weight] + arr[i].val;
				maxVal = max(maxVal,dp[w]);
			}
		}
	}
	return maxVal;
}
int main(){
	vector<stuff>arr;
	int P[10000];
	P[0] = 1;
	int N,W;
	cin >> N >> W;
	for(int i = 0; i < N;i++){
		int F = 0;
		stuff tmp;
		int quan;
		cin >> tmp.weight >> tmp.val >> quan;
		for(int i = 0;P[i] + F <= quan;i++){
			stuff T{tmp.weight*P[i],tmp.val*P[i]};
			arr.push_back(T);
			F += P[i];
			P[i+1] = 2*P[i];
		}
		tmp.weight = (quan-F)*tmp.weight;
		tmp.val = (quan-F)*tmp.val;
		arr.push_back(tmp);
	}
	cout << solve(arr,W) << endl;
	system("pause");
}