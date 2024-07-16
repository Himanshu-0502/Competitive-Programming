#include <bits/stdc++.h>
using namespace std;
class Combinatorics{
    public:
    vector<long long> inv;
    vector<long long> dfact,ifact;
    Combinatorics(int n,int mod){
        dfact.assign(n+1,1);
        inv.assign(n+1,1);
        ifact.assign(n+1,1);
        for(int i=2;i<=n;i++){
            dfact[i]=(dfact[i-1]*i)%mod;
            inv[i]=mod-(inv[mod%i]*(mod/i))%mod;
            ifact[i]=(ifact[i-1]*inv[i])%mod;
        }
    }
    int exp(long long a,long long b,int mod){
        long long ans=1;
        while(b){
            if(b&1) ans=((__int128_t)ans*a)%mod;
            a=((__int128_t)a*a)%mod;
            b>>=1;
        }
        return ans;
    }
    int inverse(int n,int mod){
        return exp(n,mod-2,mod);
    }
    int nCr(int n,int r,int mod){
        if(r>n||r<0) return 0;
        long long ans=dfact[n];
        ans=(ans*ifact[r])%mod;
        ans=(ans*ifact[n-r])%mod;
        return ans;
    }
    int nPr(int n,int r,int mod){
        if(r>n||r<0) return 0;
        long long ans=dfact[n];
        ans=(ans*ifact[n-r])%mod;
        return ans;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}