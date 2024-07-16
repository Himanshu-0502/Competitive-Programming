#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<vector<int>>> graph(n);
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back({v,i});
        graph[v].push_back({u,i});
        edges[i]={u,v};
    }
    vector<vector<int>> bridge;
    vector<bool> mark(n),used(m);
    vector<int> in(n),low(n);
    string orient(m,'?');
    int timer=0;
    function<void(int,int)> dfs=[&](int v,int p){
        mark[v]=true;
        in[v]=low[v]=timer++;
        for(auto u:graph[v]){
            if(used[u[1]]) continue;
            used[u[1]]=true;
            orient[u[1]]=(v==edges[u[1]][0]?'>':'<');
            if(mark[u[0]]){
                low[v]=min(low[v],in[u[0]]);
            }
            else{
                dfs(u[0],v);
                low[v]=min(low[v],low[u[0]]);
                if(low[u[0]]>in[v]){
                    bridge.push_back({u[0],v});
                }
            }
        }
    };
    for(int i=0;i<n;i++){
        if(!mark[i]){
            dfs(i,0);
        }
    }
    cout<<bridge.size()<<"\n";
    for(auto edge:bridge){
        cout<<edge[0]<<" "<<edge[1]<<"\n";
    }
    return 0;
}