#include<iostream>
#include<ctime>
using namespace std;
int solve(int i,int m){
	if(i == 1){
		return 1;
	}
	if(i == 0){
		return 1;
	}
	int a = solve(i-1,m);
	int b = (i > m) ? solve(i-1-m,m) : 0;
	return 2*a - b;
}

	}
}
int main(){
	int N,M;
	cin >> N >> M;
	cout << solve(N,M) << endl;
}