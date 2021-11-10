#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Graph{
	int v;
	vector<int>*Adj;
};

Graph newGraph(int N){
	Graph g;
	g.v = N;
	g.Adj = new vector<int>[N+1];
	return g;
}

Graph g;
bool checked[100001];
int dp[100001];
int dfs(int u){
	if(checked[u]){
		return dp[u];
	}
	checked[u] =  1;
	if(g.Adj[u].size() == 0){
		return 0;
	}
	int maxVal = 0;
	for(int i = 0; i < g.Adj[u].size();i++){
		int v = g.Adj[u][i];
		int val = (checked[v]) ? dp[v] : dfs(v);
		maxVal = max(maxVal,val);
	}
	dp[u] = maxVal+1;
	return dp[u];
}

int main(){
	int N,m;
	cin >> N >> m;
	g = newGraph(N);
	for(int i = 0; i < m;i++){
		int u,v;
		cin >> u >> v;
		g.Adj[u].push_back(v);
	}
	int maxL = 0;
	for(int i = 1; i <= N;i++){
		maxL = max(maxL,dfs(i));
	}
	cout << maxL << endl;
}
