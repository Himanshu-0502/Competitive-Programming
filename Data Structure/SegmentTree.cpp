#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int res;
    node(int v){
        res=v;
    }
};
node combine(node a,node b){
    node c(0);
    c.res=a.res+b.res;
    return c;
}
void build(vector<node> &tree,vector<int> &a,int n){
    for(int i=0;i<n;i++){
        tree[i+n]=node(a[i]);
    }
    for(int i=n-1;i>0;i--){
        tree[i]=combine(tree[i<<1],tree[i<<1|1]);
    }
}
node query(vector<node> &tree,int n,int p){
    node res(0);
    for(p+=n;p>0;p>>=1){
        res=combine(res,tree[p]);
    }
    return res;
}
node query(vector<node> &tree,int n,int l,int r){
    node resl(0),resr(0);
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) resl=combine(resl,tree[l++]);
        if(r&1) resr=combine(tree[--r],resr);
    }
    return combine(resl,resr);
}
void update(vector<node> &tree,int n,int p,int v){
    tree[p+=n]=node(v);
    while(p>>=1){
        tree[p]=combine(tree[p<<1],tree[p<<1|1]);
    }
}
void update(vector<node> &tree,int n,int l,int r,int v){
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
        if(l&1) tree[l]=combine(tree[l],node(v)),l++;
        if(r&1) --r,tree[r]=combine(tree[r],node(v));
    }
}
void push(vector<node> &tree,vector<int> &a,int n){
    for(int i=1;i<n;i++){
        tree[i<<1]=combine(tree[i<<1],tree[i]);
        tree[i<<1|1]=combine(tree[i<<1|1],tree[i]);
        tree[i]=node(0);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}