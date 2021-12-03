#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int m,n;
	cin >> n >> m;
	char arr[n][m];
	for(int i = 0; i < n;i++){
		for(int j = 0; j < m;j++){
			cin >> arr[i][j];
		}
	}

	vector<int>dq(1 << m,0);
	vector<int>dp(1 << m,0);
	for(int i = 0; i < n;i++){
		for(int j = 0; j < m;j++){
			for(int k = 0; k < (1 << m);k++){
				if(k & 1){
					//doc
					int newState = (k^1)>>1;
					if(arr[i][j] == '.'){
						dp[k] = min(dq[newState],dq[newState|(1 << (m-1))]);
					}else{
						if(i == 0 && j == 0){
							dp[k] = 1;
						}else{
							if(i == 0 || arr[i-1][j] == '.'){
								dp[k] = min(dq[newState],dq[newState|(1<<(m-1))])+1;
							}else{
								dp[k] = min(dq[newState]+1,dq[newState|(1<<(m-1))]);
							}
						}
					}
				}else{
					//ngang
					int newState = k >> 1;
					dp[k] = min(dq[newState],dq[newState|(1<<(m-1))]);
					if(arr[i][j] != '.' && ((j == 0 || ((newState&1) == true))) || arr[i][j-1] == '.'){
						dp[k]++;
					}
				}
			}
			dp.swap(dq);
		}
	}
	cout << *min_element(dq.begin(),dq.end()) << endl;
	system("pause");
}