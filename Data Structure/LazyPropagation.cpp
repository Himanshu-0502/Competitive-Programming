#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int len,del,res;
    node(int v){
        len=1;
        del=0;
        res=v;
    }
};
node compute(node a,node b,node c){
    a.len=b.len+c.len;
    a.res=b.res+c.res;
    if(a.del==0) return a;
    a.res=a.del*a.len;
    return a;
}
void apply(vector<node> &tree,int n,int p,int v){
    tree[p].res=v*tree[p].len;
    if(p<n) tree[p].del=v;
}
void build(vector<node> &tree,vector<int> &a,int n){
    for(int i=0;i<n;i++){
        tree[i+n]=node(a[i]);
    }
    for(int i=n-1;i>0;i--){
        tree[i]=compute(tree[i],tree[i<<1],tree[i<<1|1]);
    }
}
void pull(vector<node> &tree,int p){
    while(p>>=1) tree[p]=compute(tree[p],tree[p<<1],tree[p<<1|1]);
}
void push(vector<node> &tree,int n,int p){
    for(int s=log2(n);s>0;s--){
        int i=p>>s;
        if(tree[i].del==0) continue;
        apply(tree,n,i<<1,tree[i].del);
        apply(tree,n,i<<1|1,tree[i].del);
        tree[i].del=0;        
    }
}
void update(vector<node> &tree,int n,int l,int r,int v){
    if(v==0) return;
    int left=l+n,right=r+n;
    push(tree,n,left);
    push(tree,n,right-1);
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) apply(tree,n,l++,v);
        if(r&1) apply(tree,n,--r,v);
    }
    pull(tree,left);
    pull(tree,right-1);
}
node query(vector<node> &tree,int n,int l,int r){
    int left=l+n,right=r+n;
    push(tree,n,left);
    push(tree,n,right-1);
    node resl(0),resr(0);
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) resl=compute(resl,resl,tree[l++]);
        if(r&1) resr=compute(resr,tree[--r],resr);
    }
    return compute(resl,resl,resr);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}