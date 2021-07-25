#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

struct point{
	int x;
	int y;
};


int areaOfTriangle(point a,point b,point c){
	return abs((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
}

int main(){
	int N;
	cin >> N;
	point arr[N];
	int S[N][N];
	int res = 0;
	for(int i = 0; i < N;i++) cin >> arr[i].x >> arr[i].y;
	for(int i = 0; i < N;i++){
		int k = (i+3)%N;
		for(int j = (i+2)%N; j != (i+N-1)%N;j = (j+1)%N){
			if(j == k) k = (k+1)%N;
			S[i][j] = areaOfTriangle(arr[i],arr[j],arr[k]);
			while((k+1)%N != i && areaOfTriangle(arr[i],arr[j],arr[k]) <= areaOfTriangle(arr[i],arr[j],arr[(k+1)%N])){
				k = (k+1)%N;
				S[i][j] = areaOfTriangle(arr[i],arr[j],arr[k]);
			}

			if(i > j){
				res = max(res,S[i][j]+S[j][i]);
			}
		}
	}
	cout.precision(1);
	cout << fixed << (double)res / 2.0 << endl;
	system("pause");
}