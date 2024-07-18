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
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int l=ceill(log2(n));
    vector<vector<int>> up(l,vector<int>(n,-1));
    function<void(int,int)> dfs=[&](int v,int p){
        for(auto u:tree[v]){
            if(u==p) continue;
            up[0][u]=v;
            dfs(u,v);
        }
    };
    dfs(0,0);
    for(int i=1;i<l;i++){
        for(int j=1;j<n;j++){
            if(up[i-1][j]==-1) continue;
            up[i][j]=up[i-1][up[i-1][j]];
        }
    }
    function<int(int,int)> query=[&](int u,int k){
        for(int i=l-1;i>=0;i--){
            if(up[i][u]==-1) continue;
            if(k&(1<<i)){
                u=up[i][u];
                k-=(1<<i);
            }
        }
        return (k?-1:u);
    };
    while(q--){
        int u,k;
        cin>>u>>k;
        cout<<query(u,k)<<"\n";
    }
    return 0;
}