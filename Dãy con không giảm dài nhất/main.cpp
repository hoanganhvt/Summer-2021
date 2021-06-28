#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;

#define inf 2000000001

int main(){
	int N,D;
	int maxL = 0;
	cin >> N >> D;
	int arr[N+1];
	int last[N+1];
	last[0] = -inf;
	for(int i = 1; i <= N;i++){
		cin >> arr[i];
		last[i] = inf;
		for(int j = i; j > 0;j--){
			if(arr[i] - D > last[j-1]){
				last[j] = min(last[j],arr[i]-D);
				maxL = max(maxL,j);
			}
			else if(arr[i] + D >= last[j-1]){
				last[j] = min(last[j],last[j-1]);
				maxL = max(maxL,j);
			}
		}
	}
	cout << maxL << endl;
	system("pause");
}