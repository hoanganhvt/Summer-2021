#include<iostream>
using namespace std;

string s;
int k;

int solve(int start,int end){
	if(end-start+1 < k){
		return 0;
	}
	int count[26] = {0};
	for(int i = start;i <= end;i++){
		count[s[i]-'a']++;
	}
	for(int i = start; i <= end;i++){
		if(count[s[i]-'a']>= k){
			continue;
		}
		int left = (start <= i-1) ? solve(start,i-1) : 0;
		int right = (end >= i+1) ? solve(i+1,end) : 0;
		return max(left,right);
	}
	return end-start+1;
}
int main(){
	cin >> s >> k;
	cout << solve(0,s.length()-1) << endl;
	system("pause");
}