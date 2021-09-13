#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int>result;
	int m,n;
	cin >> m >> n;
	vector<vector<int>>arr;
	for(int i = 0; i < m;i++){
		vector<int>tmp;
		for(int j = 0; j < n;j++){
			int w;
			cin >> w;
			tmp.push_back(w);
		}
		arr.push_back(tmp);
	}
	int q;
	cin >> q;
	int x,y;
	x = 0;
	y = 0;
	for(int k = 0; k < q;k++){
		int p;
		cin >> p;
		if(p == 0){
			int a,b;
			cin >> a >> b;
			x+=a;
			y+=b;
		}
		else{
			int S = 0;
			int u,v,s,t;
			cin >> u >> v >> s >> t;
			for(int i = u-1;i < s;i++){
				for(int j = v-1; j < t;j++){
					int newI,newJ;
					newI = (i+y)%m;
					newJ = (j+x)%n;
					S += arr[newI][newJ];
				}
			}
			result.push_back(S);
		}
	}
	for(int i = 0; i < result.size();i++){
		cout << result[i] << endl;
	}
	system("pause");
}