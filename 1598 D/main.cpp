#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef pair<int,unsigned long long int>iulli;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		long long res = n*1LL*(n-1)*(n-2)/6;
		vector<pair<int,int>>Problems;
		map<int,long long>difficultyCounter;
		map<int,long long>topicCounter;
		for(int i = 0; i < n;i++){
			int a,b;
			cin >> a >> b;
			Problems.push_back(pair<int,int>(a,b));
			topicCounter[a]++;
			difficultyCounter[b]++;
		}
		long long cnt = 0;;
		for(int i = 0; i < n;i++){
			res -= ((topicCounter[Problems[i].first]-1)*1LL*(difficultyCounter[Problems[i].second]-1));
		}
		cout << res << endl;
	}
}