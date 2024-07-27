#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        vector<vector<int>> vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec.push_back({a[i][j],j});
            }
        }
        sort(vec.begin(),vec.end());
        vector<int> cnt(m);
        int siz=0;
        function<void(int)> add=[&](int i){
            cnt[i]++;
            siz+=(cnt[i]==1);
        };
        function<void(int)> rem=[&](int i){
            siz-=(cnt[i]==1);
            cnt[i]--;
        };
        int res=INT_MAX,pos=0;
        for(int i=0;i<vec.size();i++){
            while(pos<vec.size()&&siz<m) add(vec[pos++][1]);
            if(siz<m) break;
            res=min(res,vec[pos-1][0]-vec[i][0]);
            rem(vec[i][1]);
        }
        cout<<res<<"\n";
    }
    return 0;
}