#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

#define ll long long
int main(){
	vector<ll>states;
	vector<ll>arr[10000];
	for(int i = 0; i <= 15;i++){
		if(!((i << 1) & i)){
			states.push_back(i);
		}
	}
	int n;
	cin >> n;
	for(int i = 0; i < 4;i++){
		for(int j = 0; j < n;j++){
			ll tmp;
			cin >> tmp;
			arr[j].push_back(tmp);
		}
	}
	ll maxVal = INT64_MIN;
	ll dp[n][states.size()];
	for(int i = 0; i < n;i++){
		for(int j = 0; j < states.size();j++){
			ll tmpS = 0;
			int totalSelected = 0;
			for(int k = 0; k < 4;k++){
				if(states[j] &(1 << k)){
					tmpS+=arr[i][k];
					totalSelected++;
				}
			}
			dp[i][j] = tmpS;
			ll maxPrevS = 0;
			if(i != 0){
				for(int k = 0; k < states.size();k++){
					if(!(states[j] & states[k])){
						maxPrevS = max(maxPrevS,dp[i-1][k]);
					}
				}
			}
			dp[i][j] += maxPrevS;
			if(totalSelected){
				maxVal = max(maxVal,dp[i][j]);
			}
		}
	}
	cout << maxVal << endl;
	system("pause");
}