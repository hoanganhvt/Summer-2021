#include<iostream>
#include<set>
#include<vector>

using namespace std;

#define oo 1e9
typedef pair<int,int>II;

struct Graph{
	int V;
	vector<II>*Adj;
};

void newGraph(Graph *g,int N){
	g->V = N;
	g->Adj = new vector<II>[N+1];
}

void addEdg(Graph *g,int State,int u,int v,int cost){
	g->Adj[u].push_back(II(cost,v));
	if(State == 2){
		g->Adj[v].push_back(II(cost,u));
	}
}

Graph g;
set<II>S;
long long cnt[10000];
int L[10000];

void Dijkstra(int Start){
	for(int i = 2; i <= g.V;i++){
		L[i] = oo;
	}
	L[Start] = 0;
	cnt[Start] = 1;
	S.insert(II(0,1));
	while(S.size()){
		II t = *S.begin();
		S.erase(t);
		int u = t.second;
		int w = t.first;
		for(int i = 0; i < g.Adj[u].size();i++){
			int v = g.Adj[u][i].second;
			int cost = g.Adj[u][i].first;

			if(L[u]+cost > L[v]) continue;
			else if(L[u]+cost == L[v]){
				cnt[v] += cnt[u];
			}
			else{
				S.erase(II(L[v],v));
				L[v] = L[u]+cost;
				cnt[v] = cnt[u];
				S.insert(II(L[v],v));
			}
		}
	}
}
int main(){
	int N,m;
	cin >> N >> m;
	newGraph(&g,N);
	for(int i = 0; i < m;i++){
		int u,v,cost,state;
		cin >> state >> u >> v >> cost;
		addEdg(&g,state,u,v,cost);
	}
	Dijkstra(1);
	cout << L[N] << " " << cnt[N] << endl;
}