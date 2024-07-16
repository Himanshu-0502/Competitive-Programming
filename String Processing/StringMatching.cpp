#include <bits/stdc++.h>
using namespace std;
vector<int> prefix(int n,string s){
    vector<int> ans(n);
    for(int i=1;i<n;i++){
        int j=ans[i-1];
        while(j>0&&s[i]!=s[j]){
            j=ans[j-1];
        }
        ans[i]=j+(s[i]==s[j]);
    }
    return ans;
}
vector<int> match(int n,vector<int> pref){
    vector<int> ans;
    for(int i=n;i<pref.size();i++){
        if(pref[i]==n){
            ans.push_back(i-2*n);
        }
    }
    return ans;
}
vector<int> count(int n,vector<int> pref){
    vector<int> ans(n+1);
    for(int i=0;i<n;i++){
        ans[pref[i]]++;
    }
    for(int i=n-1;i>0;i--){
        ans[pref[i-1]]+=ans[i];
    }
    for(int i=0;i<=n;i++){
        ans[i]++;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}