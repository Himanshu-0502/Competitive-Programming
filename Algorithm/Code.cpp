#include <bits/stdc++.h>
using namespace std;
int findCapableWinners(vector<int> power_a,vector<int> power_b,vector<int> power_c){
    int n=power_a.size();
    vector<vector<int>> vec(n);
    for(int i=0;i<n;i++){
        vector<int> temp={power_a[i],power_b[i],power_c[i]};
        sort(temp.begin(),temp.end());
        vec[i]=temp;
    }
    vector<int> pref_min(n),pref_mid(n);
    pref_min[0]=vec[0][0];
    pref_mid[0]=vec[0][1];
    for(int i=1;i<n;i++){
        pref_min[i]=max(pref_min[i-1],vec[i][0]);
        pref_mid[i]=max(pref_mid[i-1],vec[i][1]);
    }
    vector<int> suff_min(n),suff_mid(n);
    suff_min[n-1]=vec[n-1][0];
    suff_mid[n-1]=vec[n-1][1];
    for(int i=n-2;i>=0;i--){
        suff_min[i]=max(suff_min[i+1],vec[i][0]);
        suff_mid[i]=max(suff_mid[i+1],vec[i][1]);
    }
    int res=0;
    for(int i=0;i<n;i++){
        int curr_max=vec[i][2];
        int curr_mid=vec[i][1];
        int prev_mid=(i?pref_mid[i-1]:0);
        int prev_min=(i?pref_min[i-1]:0);
        int next_mid=(i<n-1?suff_mid[i+1]:0);
        int next_min=(i<n-1?suff_min[i+1]:0);
        int reqi_mid=max(prev_mid,next_mid);
        int reqi_min=max(prev_min,next_min);
        if(curr_max>reqi_mid&&curr_mid>reqi_min){
            res+=1;
        }
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    {
        vector<int> power_a={9,4,2};
        vector<int> power_b={5,12,10};
        vector<int> power_c={11,3,13};
        cout<<findCapableWinners(power_a,power_b,power_c)<<"\n";
    }
    {
        vector<int> power_a={3,4,1,16};
        vector<int> power_b={2,11,5,6};
        vector<int> power_c={8,7,9,10};
        cout<<findCapableWinners(power_a,power_b,power_c)<<"\n";
    }
    return 0;
}