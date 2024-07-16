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
    vector<int> side(n,-1);
    bool is_bipartite=true;
    function<void(int)> bfs=[&](int src){
        queue<int> q;
        q.push(src);
        side[src]=0;
        while(q.size()){
            int v=q.front();
            q.pop();
            for(auto u:graph[v]){
                if(side[u]==-1){
                    side[u]=side[v]^1;
                    q.push(u);
                }
                else{
                    is_bipartite&=(side[u]!=side[v]);
                }
            }
        }           
    };
    for(int i=0;i<n;i++){
        if(side[i]==-1) bfs(i);
    }
    if(is_bipartite){
        cout<<"Yes\n";
        for(int i=0;i<n;i++){
            cout<<side[i]<<" \n"[i==n-1];
        }
    }
    else{
        cout<<"No\n";
    }
    return 0;
}