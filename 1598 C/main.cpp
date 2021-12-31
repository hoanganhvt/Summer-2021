#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
 
#define ll unsigned long long int
 
ll querrySum(ll Start,ll End){
	ll Res = End*(End+1)/2;
	Res -= (Start*(Start+1)/2);
	Res += Start;
	return Res;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		map<ll,int>Counter;
		int n;
		cin >> n;
		ll S = 0;
		for(int i = 0;i < n;i++){
			ll tmp;
			cin >> tmp;
			Counter[tmp]++;
			S += tmp;
		}
		if((2*S)%n == 0){
			ll cnt = 0;
			for(auto i : Counter){
				if(2*S/n-i.first == i.first){
					cnt += (i.second*(i.second-1)/2);
				}else if(Counter[2*S/n-i.first] && Counter[i.first]){
					cnt+= (Counter[i.first]*Counter[2*S/n-i.first]);
					Counter[i.first] = 0;
					Counter[2*S/n-i.first] = 0;
				}
			}
			cout << cnt << endl;
		}else{
			cout << 0 << endl;
		}
	}
}