#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> side(n, -1);
    function<bool(int, int)> dfs = [&](int v, int c) {
        side[v] = c;
        for (auto u : graph[v]) {
            if (side[u] == -1) {
                if (!dfs(u, !c)) {
                    return false;
                }
            } else {
                if (side[u] == c) {
                    return false;
                }
            }
        }
        return true;
    };

    bool isBipartite = true;
    for (int i = 0; i < n; i++) {
        if (side[i] == -1) {
            isBipartite &= dfs(i, 0);
        }
    }

    if (isBipartite) {
        cout << "Yes\n";
        for (int i = 0; i < n; i++) {
            cout << side[i] << " \n" [i + 1 == n];
        }
    } else {
        cout << "No\n";
    }
    
    return 0;
}