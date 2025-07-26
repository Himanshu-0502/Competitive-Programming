#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<vector<int>>> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    int l = ceill(log2(n));
    vector<vector<int>> up(l, vector<int> (n));
    vector<vector<long long>> dp(l, vector<long long> (n));
    vector<int> tin(n), tout(n);
    int timer = 0;
    function<void(int, int)> dfs = [&](int v, int p) {
        tin[v] = timer++;
        for (auto edge : tree[v]) {
            int u = edge[0], w = edge[1];
            if (u == p) continue;
            up[0][u] = v;
            dp[0][u] = w;
            dfs(u, v);
        }
        tout[v] = timer++;
    };
    dfs(0, 0);

    for (int i = 1; i < l; i++) {
        for (int j = 1; j < n; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
            dp[i][j] = dp[i - 1][j] + dp[i - 1][up[i - 1][j]];
        }
    }

    function<bool(int, int)> isAncestor = [&](int u, int v) {
        return (tin[u] <= tin[v] && tout[u] >= tout[v]);
    };

    function<long long(int, int)> compute = [&](int u, int v) {
        long long res = 0;
        for (int i = l - 1; i >= 0; i--) {
            if (isAncestor(up[i][u], v)) continue;
            res += dp[i][u];
            u = up[i][u];
        }
        return res + dp[0][u];
    };

    function<long long(int, int)> query = [&](int u, int v) {
        long long res = 0;
        if (!isAncestor(u, v)) res += compute(u, v);
        if (!isAncestor(v, u)) res += compute(v, u);
        return res;
    };

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << "\n";
    }
    
    return 0;
}