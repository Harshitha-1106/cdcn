#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<vector>
#include<queue>

using namespace std;

vector<int> dij(int v,vector<vector<pair<int,int>>> adj,int s){
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	vector<int> dist(v,1e9);
	dist[s]=0;
	pq.push({0,s});
	while(!pq.empty()){
		int dis=pq.top().first;
		int node=pq.top().second;
pq.pop();
		for(auto it:adj[node]){
			int ew=it.second;
			int adjn=it.first;
			if(ew+dis<dist[adjn]){
				dist[adjn]=ew+dis;
				pq.push({dist[adjn],adjn});
			}
}
}
return dist;
}


int main(){

	int v,e;
	cin>>v>>e;
vector<vector<pair<int,int>>>adj(v);
       for(int i=0;i<e;i++){
		int u,x,w;
		cin>>u>>x>>w;
		adj[u].push_back({x,w});
		adj[x].push_back({u,w});
 }
 vector<int> dis=dij(v,adj,0);
for(int i=0;i<v;i++){
   cout<<dis[i]<<" ";
}
}