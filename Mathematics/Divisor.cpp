#include <bits/stdc++.h>
using namespace std;
vector<int> spf(int n){
    vector<int> factor(n+1);
    iota(factor.begin(),factor.end(),0);
    factor[0]=factor[1]=-1;
    for(int i=2;i*i<=n;i++){
        if(i!=factor[i]) continue;
        for(int j=i*i;j<=n;j+=i){
            if(j!=factor[j]) continue;
            factor[j]=i;
        }
    }
    return factor;
}
vector<long long> factorize(int n,vector<int> &factor){
    vector<long long> factors;
    while(factor[n]!=-1){
        factors.push_back(factor[n]);
        n/=factor[n];
    }
    return factors;
}
vector<long long> divisor(vector<long long> &factors){
    vector<long long> divisors={1};
    int n=factors.size();
    int prev=0;
    for(int i=0;i<n;i++){
        if(i!=n-1&&factors[i]==factors[i+1]) continue;
        int len=divisors.size();
        long long prime=factors[i];
        for(int j=0;j+prev<i+1;j++){
            for(int k=0;k<len;k++){
                divisors.push_back(divisors[k]*prime);
            }
            prime*=factors[i];
        }
        prev=i+1;
    }
    sort(divisors.begin(),divisors.end());
    return divisors;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}