#include <bits/stdc++.h>
using namespace std;

int mod[2] = {1000000007, 1000000009};
int inv[2] = {190839696, 262773725};
int bas[2] = {131, 137};

vector<long long> value(int n, string& s) {
    long long pow[2] = {bas[0], bas[1]};
    vector<long long> ans(2, s[0]);

    for (int i = 1; i < n; i++) {
        ans[0] = (ans[0] + pow[0] * s[i]) % mod[0];
        ans[1] = (ans[1] + pow[1] * s[i]) % mod[1];

        pow[0] = (pow[0] * bas[0]) % mod[0];
        pow[1] = (pow[1] * bas[1]) % mod[1];
    }

    return ans;
}

vector<vector<long long>> prefix(int n, string& s) {
    long long pow[2] = {bas[0], bas[1]};
    vector<vector<long long>> ans(n, vector<long long> (2, s[0]));

    for (int i = 1; i < n; i++) {
        ans[i][0] = (ans[i - 1][0] + pow[0] * s[i]) % mod[0];
        ans[i][1] = (ans[i - 1][1] + pow[1] * s[i]) % mod[1];

        pow[0] = (pow[0] * bas[0]) % mod[0];
        pow[1] = (pow[1] * bas[1]) % mod[1];
    }

    return ans;
}

vector<vector<long long>> inverse(int n) {
    vector<vector<long long>> ans(n, vector<long long> (2, 1));

    for (int i = 1; i < n; i++) {
        ans[i][0] = (ans[i - 1][0] * inv[0]) % mod[0];
        ans[i][1] = (ans[i - 1][1] * inv[1]) % mod[1];
    }

    return ans;
}

vector<long long> subarray(vector<vector<long long>>& hash, vector<vector<long long>>& invt, int l, int r) {
    vector<long long> have(2);

    have[0] = ((hash[r][0] - (l ? hash[l - 1][0] : 0) + mod[0]) * invt[l][0]) % mod[0];
    have[1] = ((hash[r][1] - (l ? hash[l - 1][1] : 0) + mod[1]) * invt[l][1]) % mod[1];

    return have;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}