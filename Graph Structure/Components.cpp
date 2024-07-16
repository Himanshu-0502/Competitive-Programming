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
    set<int> marked;
    for(int i=0;i<n;i++){
        marked.insert(i);
    }
    vector<int> comp(n,-1);
    function<void(int,int)> dfs=[&](int v,int p){
        comp[v]=p;
        marked.erase(v);
        set<int> temp;
        for(auto u:graph[v]){
            if(marked.find(u)!=marked.end()){
                marked.erase(u);
                temp.insert(u);
            }
        }
        swap(marked,temp);
        for(auto u:temp){
            dfs(u,p);
        }
    };
    for(int i=0;i<n;i++){
        if(marked.find(i)!=marked.end()){
            dfs(i,i);
        }
    }
    for(int i=0;i<n;i++){
        cout<<comp[i]<<" \n"[i==n-1];
    }
    return 0;
}