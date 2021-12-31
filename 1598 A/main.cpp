#include<iostream>
#include<vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	cin.ignore();
	string realRes;
	while(t--){
		int n;
		cin >> n;
		cin.ignore();
		string res = "YES\n";
		string ar[2];
		cin >> ar[0];
		cin.ignore();
		cin >> ar[1];
		for(int i = 0; i < n;i++){
			if((ar[0][i]-'0')+(ar[1][i]-'0') == 2){
				res = "NO\n";
				break;
			}
		}
		realRes += res;
	}
	cout <<realRes;
}