#include<iostream>
using namespace std;

#define inf 2147483647
int arr[10000];

int sigma(int start,int end){
	int s = 0;
	for(int i = start; i <= end;i++){
		s += arr[i];
	}
	return s;
}


int solve(int i,int k){
	if(i == 1){
		return arr[1];
	}
	if(k == 1){
		return sigma(1,i);
	}

	int best = inf;
	for(int j = i;j >= 1;j--){
		best = min(best,max(solve(j,k-1),sigma(j+1,i)));
	}
	return best;
}
int main(){
	int N,k;
	cin >> N >> k;
	for(int i = 1; i <= N;i++){
		cin >> arr[i];
	}
	cout << solve(N,k) << endl;
	system("pause");
}