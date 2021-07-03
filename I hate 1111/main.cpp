#include<iostream>
using namespace std;

bool solve(int N){
	int m = N % 11;
	float x = (N-m*111)/11;
	return (x - (int)x == 0 && x >= 0);
}
int main(){
	int N;
	cin >> N;
	int arr[N+1];
	for(int i = 0; i < N;i++){
		cin >> arr[i];
	}
	for(int i = 0; i < N;i++){
		string tmp = (solve(arr[i])) ? "YES" : "NO";
		cout << tmp << endl;
	}
}