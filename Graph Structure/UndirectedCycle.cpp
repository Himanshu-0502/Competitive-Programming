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
    vector<bool> mark(n);
    vector<int> parent(n);
    int start=0,end=0;
    function<bool(int,int)> dfs=[&](int v,int p){
        mark[v]=true;
        for(auto u:graph[v]){
            if(mark[u]){
                if(u==p) continue;
                start=u;
                end=v;
                return true;
            }
            parent[u]=v;
            if(dfs(u,v)) return true;
        }
        return false;
    };
    if(dfs(0,0)){
        vector<int> path;
        for(int i=end;i!=start;i=parent[i]) path.push_back(i);
        path.push_back(start);
        reverse(path.begin(),path.end());
        cout<<"Yes\n";
        cout<<path.size()<<"\n";
        for(auto i:path) cout<<i<<" \n"[i==path.back()];
    }
    else{
        cout<<"No\n";
    }
    return 0;
}