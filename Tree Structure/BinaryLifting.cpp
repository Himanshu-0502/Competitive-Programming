#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<vector<pair<int,int>>> tree(n);
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
    }
    int l=ceill(log2(n));
    vector<vector<int>> up(l,vector<int>(n));
    vector<vector<int>> dp(l,vector<int>(n));
    vector<int> in(n),out(n);
    int timer=0;
    function<void(int,int)> dfs=[&](int v,int p){
        in[v]=timer++;
        for(auto [u,w]:tree[v]){
            if(u==p) continue;
            up[0][u]=v;
            dp[0][u]=w;
            dfs(u,v);
        }
        out[v]=timer++;
    };
    dfs(0,0);
    for(int i=1;i<l;i++){
        for(int j=1;j<n;j++){
            up[i][j]=up[i-1][up[i-1][j]];
            dp[i][j]=max(dp[i-1][j],dp[i-1][up[i-1][j]]);
        }
    }
    function<bool(int,int)> isAncestor=[&](int u,int v){
        return (in[u]<=in[v]&&out[u]>=out[v]);
    };
    function<int(int,int)> compute=[&](int u,int v){
        int res=0;
        for(int i=l-1;i>=0;i--){
            if(isAncestor(up[i][u],v)) continue;
            res=max(res,dp[i][u]);
            u=up[i][u];
        }
        return max(res,dp[0][u]);
    };
    function<int(int,int)> query=[&](int u,int v){
        int res=0;
        if(!isAncestor(u,v)) res=max(res,compute(u,v));
        if(!isAncestor(v,u)) res=max(res,compute(v,u));
        return res;
    };
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<query(u,v)<<"\n";
    }
    return 0;
}