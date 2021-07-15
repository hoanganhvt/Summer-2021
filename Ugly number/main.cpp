#include<iostream>
using namespace std;

#define ull unsigned long long int


ull minNum(ull a,ull b,ull c){
	ull Min = (a <= b) ? a : b;
	Min = (Min <= c) ? Min : c;
	return Min;
}

ull solve(int n){
	ull *f = new ull[n];
	f[0] = 1;
	int mulNum[3] = {0,0,0};
	const ull defNum[3] = {2,3,5};
	for(int i = 1; i < n;i++){
		f[i] = minNum(defNum[0]*f[mulNum[0]],defNum[1]*f[mulNum[1]],defNum[2]*f[mulNum[2]]);
		for(int j = 0; j < 3;j++){
			if(f[i] == defNum[j]*f[mulNum[j]]){
				mulNum[j] += 1;
			}
		}
	}
	return f[n-1];
}
int main(){
	int N;
	cin >> N;
	cout << solve(N) << endl;
	system("pause");
}