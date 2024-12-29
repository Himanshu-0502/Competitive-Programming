#include <bits/stdc++.h>
using namespace std;

class DSU {
    public:
    vector<int> par;
    vector<int> siz;

    DSU(int n) {
        par.assign(n, 0);
        iota(par.begin(), par.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int v) {
        if (v == par[v]) {
            return v;
        }
        return par[v] = find(par[v]);
    }

    bool same(int u, int v) {
        return (find(u) == find(v));
    }

    bool merge(int u, int v) {
        if (same(u, v)) {
            return true;
        }

        u = par[u];
        v = par[v];

        if (siz[u] < siz[v]) {
            swap(u, v);
        }

        siz[u] += siz[v];
        par[v] = par[u];

        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}