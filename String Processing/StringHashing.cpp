#include <bits/stdc++.h>
using namespace std;
int mod0=1000000007,mod1=1000000009;
int inv0=190839696,inv1=262773725;
int base0=131,base1=137;
vector<long long> hashValue(int n,string s){
    long long power0=base0;
    long long power1=base1;
    vector<long long> ans(2,s[0]);
    for(int i=1;i<n;i++){
        ans[0]=(ans[0]+power0*s[i])%mod0;
        ans[1]=(ans[1]+power1*s[i])%mod1;
        power0=(power0*base0)%mod0;
        power1=(power1*base1)%mod1;
    }
    return ans;
}
vector<vector<long long>> hashPrefix(int n,string s){
    long long power0=base0;
    long long power1=base1;
    vector<vector<long long>> ans(n,vector<long long>(2,s[0]));
    for(int i=1;i<n;i++){
        ans[i][0]=(ans[i-1][0]+power0*s[i])%mod0;
        ans[i][1]=(ans[i-1][1]+power1*s[i])%mod1;
        power0=(power0*base0)%mod0;
        power1=(power1*base1)%mod1;
    }
    return ans;
}
vector<vector<long long>> invPower(int n){
    vector<vector<long long>> ans(n,vector<long long>(2,1));
    for(int i=1;i<n;i++){
        ans[i][0]=(ans[i-1][0]*inv0)%mod0;
        ans[i][1]=(ans[i-1][1]*inv1)%mod1;
    }
    return ans;
}
vector<long long> subarray(vector<vector<long long>> &hash,vector<vector<long long>> &inve,int start,int end){
    vector<long long> value(2);
    value[0]=((hash[end][0]-(start?hash[start-1][0]:0)+mod0)*inve[start][0])%mod0;
    value[1]=((hash[end][1]-(start?hash[start-1][1]:0)+mod1)*inve[start][1])%mod1;
    return value;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}