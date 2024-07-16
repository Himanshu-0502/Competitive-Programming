#include <bits/stdc++.h>
using namespace std;
class BIT{
    public:
    int n;
    vector<int> bit;
    BIT(int size){
        n=size;
        bit.assign(size+1,0);
    }
    void add(int i,int v){
        for(i++;i<=n;i+=i&-i) bit[i]+=v;
    }
    int sum(int i){
        int res=0;
        for(i++;i>=1;i-=i&-i) res+=bit[i];
        return res;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}