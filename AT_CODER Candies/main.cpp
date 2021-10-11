#include<iostream>

using namespace std;

#define div 1000000007
int main(){
	unsigned long long int N,k;
	cin >> N >> k;
	int past[100001];
	int present[100001];
	for(int i = 0; i <= k;i++){
		past[i] = 1;
	}
	present[0] = 1;
	for(int i = 1; i <= N;i++){
		int Ai;
		cin >> Ai;
		for(int j = 1; j <= k;j++){
			if(j <= Ai){
				present[j] = (past[j])%div;
				present[j] = (present[j]+present[j-1]) % div;
				continue;
			}
			present[j] = (j-Ai-1 >= 0) ? (past[j]-past[j-Ai-1])%div : 0;
			present[j] = (present[j]+present[j-1]) % div;
		}

		swap(present,past);
	}
	cout << (past[k]-past[k-1])%div << endl;
	system("pause");
}