#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<vector<int>> tree(n);
    for(int i=1;i<n;i++){
        int p;
        cin>>p;
        tree[i].push_back(p);
        tree[p].push_back(i);
    }
    int l=ceill(log2(n));
    vector<vector<int>> up(l,vector<int>(n));
    vector<int> in(n),out(n);
    int timer=0;
    function<void(int,int)> dfs=[&](int v,int p){
        in[v]=timer++;
        for(auto u:tree[v]){
            if(u==p) continue;
            up[0][u]=v;
            dfs(u,v);
        }
        out[v]=timer++;
    };
    dfs(0,0);
    for(int i=1;i<l;i++){
        for(int j=1;j<n;j++){
            up[i][j]=up[i-1][up[i-1][j]];
        }
    }
    function<bool(int,int)> isAncestor=[&](int u,int v){
        return (in[u]<=in[v]&&out[u]>=out[v]);
    };
    function<int(int,int)> lca=[&](int u,int v){
        if(isAncestor(u,v)) return u;
        if(isAncestor(v,u)) return v;
        for(int i=l-1;i>=0;i--){
            if(isAncestor(up[i][u],v)) continue;
            u=up[i][u];
        }
        return up[0][u];
    };
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<"\n";
    }
    return 0;
}