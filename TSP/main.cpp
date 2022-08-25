#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int Distance[15][15];
int memo[15][15];
int N;

int solve(int i,int state){
	if(state == pow(2,N)-1){
		return Distance[i][0];
	}
	int cur = INT_MAX;
	for(int j = 0; j < N;j++){
		if(!((1 << j)&state)){
			int newState = (1<<j)|state;
			cur = min(cur,solve(j,newState)+Distance[i][j]);
		}
	}
	return cur;
}
int main(){
	cin >> N;
	for(int i = 0; i < N;i++){
		for(int j = 0;j < N;j++){
			cin >> Distance[i][j];
		}
	}
	cout << solve(0,1) << endl;
	system("pause");
}