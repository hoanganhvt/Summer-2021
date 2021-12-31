#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

typedef pair<int,int> II;
vector<II>seq;
int towerOfHanoi(int n,int S,int t,int D){
	if(n == 1){
		seq.push_back(II(S,D));
		return 1;
	}else{
		int res = towerOfHanoi(n-1,S,D,t);
		seq.push_back(II(S,D));
		res += towerOfHanoi(n-1,t,S,D)+1;
		return res;
	}
}
int main(){
	int n;
	cin >> n;
	cout << towerOfHanoi(n,1,2,3) << endl;
	for(int i = 0; i < seq.size();i++){
		cout << seq[i].first << " " << seq[i].second << endl;
	}
}