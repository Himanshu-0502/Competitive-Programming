#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> floydWarshall(int n,vector<vector<pair<int,int>>> graph){
    vector<vector<long long>> dist(n,vector<long long>(n,LLONG_MAX));
    for(int v=0;v<n;v++){
        dist[v][v]=0;
        for(auto [u,w]:graph[v]){
            dist[v][u]=min(dist[v][u],(long long)w);
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    return dist;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    function<vector<long long>(int)> dijkstra=[&](int src){
        vector<long long> dist(n,LLONG_MAX);
        vector<int> par(n,-1);
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>> pq;
        dist[src]=0;
        pq.push({dist[src],src});
        while(pq.size()){
            int v=pq.top()[1];
            int d=pq.top()[0];
            pq.pop();
            if(d!=dist[v]) continue;
            for(auto [u,w]:graph[v]){
                if(dist[v]+w<dist[u]){
                    dist[u]=dist[v]+w;
                    par[u]=v;
                    pq.push({dist[u],u});
                }
            }
        }
        return dist;
    };
    vector<vector<long long>> dp=floydWarshall(n,graph);
    vector<long long> dist=dijkstra(0);
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" \n"[i==n-1];
    }
    return 0;
}