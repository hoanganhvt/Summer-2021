#include<iostream>
using namespace std;
int main(){
	int N,k;
	cin >> N >> k;
	int a[N+1];
	for(int i =1;i <= N;i++){
		cin >> a[i];
	}
	bool dp[k+1] = { 0 };
	for(int i = 1;i <= k;i++){
		if(dp[i] == 0){
			for(int j = 1; j <= N;j++){
				bool tmp = (i-a[j] >= 0) ? !dp[i-a[j]] : 0;
				if(tmp == 1){
					dp[i] = tmp;
					break;
				}
			}
		}
	}
	if(dp[k] == 1){
		cout << "First" << endl;
	}
	else{
		cout << "Second" << endl;
	}
	system("pause");
}