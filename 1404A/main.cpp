#include<iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	string realRes;
	while(t--){
		int n,k;
		cin >> n >> k;
		cin.ignore();
		string s;
		cin >> s;
		cin.ignore();
		int cnt0 = 0;
		int cnt1 = 0;
		string res = "YES\n";
		for(int i = 0; i < k;i++){
			for(int j = i; j < n;j+=k){
				if(s[i] == '?'){
					s[i] = s[j];
				}else if(s[j] == '?'){
					s[j] =s[i];
				}
				if(s[i] != s[j]){
					res = "NO\n";
				}
			}
			if(s[i]-'0' == 0){
				cnt0++;
			}else if(s[i]-'0' == 1){
				cnt1++;
			}
			if(cnt0 > k/2 || cnt1 >k/2){
				res = "NO\n";
			}
		}
		realRes += res;
	}
	cout << realRes;
}