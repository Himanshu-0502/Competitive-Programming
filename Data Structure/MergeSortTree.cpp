#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> &a,vector<int> &b){
    vector<int> c;
    int i=0,j=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]<b[j]) c.push_back(a[i++]);
        else c.push_back(b[j++]);
    }
    while(i<a.size()) c.push_back(a[i++]);
    while(j<b.size()) c.push_back(b[j++]);
    return c;
}
void build(vector<vector<int>> &tree,vector<int> &a,int n){
    for(int i=0;i<n;i++){
        tree[i+n]={a[i]};
    }
    for(int i=n-1;i>0;i--){
        tree[i]=merge(tree[i<<1],tree[i<<1|1]);
    }
}
int compute(vector<int> &a,int v){
    return (lower_bound(a.begin(),a.end(),v)-a.begin());
}
int query(vector<vector<int>> &tree,int n,int l,int r,int k){
    int res=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) res+=compute(tree[l++],k);
        if(r&1) res+=compute(tree[--r],k);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}