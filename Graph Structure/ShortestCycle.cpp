#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    function<int(int)> directed=[&](int src){
        int ans=n+1;
        vector<int> dist(n,-1);
        queue<int> q;
        dist[src]=0;
        q.push(src);
        while(q.size()){
            int v=q.front();
            q.pop();
            for(auto u:graph[v]){
                if(dist[u]==-1){
                    dist[u]=dist[v]+1;
                    q.push(u);
                    continue;
                }
                if(u==src){
                    ans=min(ans,dist[v]+1);
                    continue;
                }
            }
        }
        return ans;
    };
    function<int(int)> undirected=[&](int src){
        int ans=n+1;
        vector<int> dist(n,-1);
        vector<int> par(n,-1);
        queue<int> q;
        dist[src]=0;
        q.push(src);
        while(q.size()){
            int v=q.front();
            q.pop();
            for(auto u:graph[v]){
                if(dist[u]==-1){
                    dist[u]=dist[v]+1;
                    par[u]=v;
                    q.push(u);
                    continue;
                }
                if(par[u]!=v&&par[v]!=u){
                    ans=min(ans,dist[u]+dist[v]+1);
                    continue;
                }
            }
        }
        return ans;
    };
    int dsc=n+1,usc=n+1;
    for(int i=0;i<n;i++){
        dsc=min(dsc,directed(i)),usc=min(usc,undirected(i));
    }
    cout<<(dsc<=n?dsc:-1)<<" "<<(usc<=n?usc:-1)<<"\n";
    return 0;
}