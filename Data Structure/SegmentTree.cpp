#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int ans;
    Node(int val) {
        ans = val;
    }
};

Node combine(Node a, Node b) {
    Node c(0);
    c.ans = a.ans + b.ans;
    return c;
}

void build(vector<Node> &tree, vector<int> &a, int n) {
    for (int i = 0; i < n; i++) {
        tree[i + n] = Node(a[i]);
    }
    for (int i = n - 1; i > 0; i--) {
        tree[i] = combine(tree[(i << 1)], tree[(i << 1 | 1)]);
    }
}

Node query(vector<Node> &tree, int n, int l, int r) {
    Node ansl(0), ansr(0);
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            ansl = combine(ansl, tree[l]);
            l += 1;
        }
        if (r & 1) {
            r -= 1;
            ansr = combine(tree[r], ansr);
        }
    }
    return combine(ansl, ansr);
}

void update(vector<Node> &tree, int n, int p, int v) {
    tree[p += n] = Node(v);
    while (p >>= 1) {
        tree[p] = combine(tree[(p << 1)], tree[(p << 1 | 1)]);
    }
}

Node query(vector<Node> &tree, int n, int p) {
    Node ans(0);
    for (p += n; p > 0; p >>= 1) {
        ans = combine(ans, tree[p]);
    }
    return ans;
}

void update(vector<Node> &tree, int n, int l, int r, int v) {
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            tree[l] = combine(tree[l], Node(v));
            l += 1;
        } else {
            r -= 1;
            tree[r] = combine(tree[r], Node(v));
        }
    }
}

void push(vector<Node> &tree, int n) {
    for (int i = 1; i < n; i++) {
        tree[(i << 1)] = combine(tree[(i << 1)], tree[i]);
        tree[(i << 1 | 1)] = combine(tree[(i << 1 | 1)], tree[i]);
        tree[i] = Node(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    return 0;
}