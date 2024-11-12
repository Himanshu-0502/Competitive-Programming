#include <bits/stdc++.h>
using namespace std;
class DSU{
    public:
    vector<int> p,s;
    DSU(int n){
        p.assign(n,0);
        iota(p.begin(),p.end(),0);
        s.assign(n,1);
    }
    int find(int v){
        if(v==p[v]) return v;
        return p[v]=find(p[v]);
    }
    bool merge(int u,int v){
        if(find(u)==find(v)) return true;
        u=p[u];
        v=p[v];
        if(s[u]<s[v]) swap(u,v);
        s[u]+=s[v];
        p[v]=p[u];
        return false;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}