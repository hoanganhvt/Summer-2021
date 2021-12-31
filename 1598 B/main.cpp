#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
int main(){
	int t;
	cin >> t;
	string RES;
	while(t--){
		int n;
		cin >> n;
		vector<vector<int>>arr(5);
		string res = "NO\n";
		vector<vector<bool>>checker(5,vector<bool>(1000,0));
		for(int i = 0;i < n;i++){
			for(int j = 0; j < 5;j++){
				bool tmp;
				cin >> tmp;
				if(tmp){
					arr[j].push_back(i);
					checker[j][i] = 1;
				}
			}
		}
		for(int i = 0; i < 5;i++){
			if(arr[i].size() >= n/2){
				for(int j = i+1; j < 5;j++){
					if(arr[j].size() >= n/2){
						int cnt = 0;
						for(int k = 0; k < arr[i].size();k++){
							if(checker[j][arr[i][k]]){
								cnt++;
							}
						}
						int l1 = arr[i].size();
						int l2 = arr[j].size();
						if(cnt == (l1-n/2)+(l2-n/2)){
							res = "YES\n";
							goto endGame;
						}
					}
				}
			}
		}
		endGame:RES += res;
	}
	cout << RES;
}