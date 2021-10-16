#include<iostream>
#include<algorithm>
using namespace std;

long long sumGet[401];
int N;

long long int getSum(int start,int end){
	return sumGet[end]-sumGet[start-1];
}

long long int minSum(long long int arr[],int N){
	long long int dp[N+1][N+1];
	for(int s = 0; s <= N-1;s++){
		for(int i = 1; i+s <= N;i++){
			int j = i+s;
			if(i == j){
				dp[i][j] = 0;
			}
			else if(j == i+1){
				dp[i][j] = arr[i]+arr[j];
			}
			else{
				long long int minVal = INT64_MAX;
				for(int k = i+1;k <=j;k++){
					minVal = min(minVal,dp[i][k-1]+dp[k][j]);
				}
				dp[i][j] = minVal+getSum(i,j);
			}
		}
	}
	return dp[1][N];
}


int main(){
	sumGet[0] = 0;
	int N;
	cin >> N;
	long long int arr[N+1];
	for(int i = 1; i <= N;i++){
		cin >> arr[i];
		sumGet[i] = sumGet[i-1]+arr[i];
	}
	cout << minSum(arr,N) << endl;
	system("pause");
}