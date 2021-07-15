#include<iostream>
using namespace std;

int solve(int S,int k){
	if(S == k){
		return 1;
	}
	if(k > S){
		return 0;
	}
	return solve(S-k,k) + solve(S,k+1);
}
int main(){
	int N;
	cin >> N;
	cout << solve(N,1) << endl;
	system("pause");
}