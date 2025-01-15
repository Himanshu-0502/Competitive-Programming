#include <bits/stdc++.h>
using namespace std;

vector<int> spf(int n) {
    vector<int> factor(n + 1);
    iota(factor.begin(), factor.end(), 0);
    factor[0] = factor[1] = -1;

    for (int i = 2; i * i <= n; i++) {
        if (i == factor[i]) {
            for (int j = i * i; j <= n; j += i) {
                if (j == factor[j]) {
                    factor[j] = i;
                }
            }
        }
    }
    return factor;
}

vector<int> factorize(int n, vector<int> &factor) {
    vector<int> factors;
    while (factor[n] != -1) {
        factors.push_back(factor[n]);
        n /= factor[n];
    }
    return factors;
}

vector<int> divisor(vector<int> &factors) {
    vector<int> divisors = {1};
    int n = factors.size(), prev = 0;
    
    for (int i = 0; i < n; i++) {
        if (i == n - 1 || factors[i] != factors[i + 1]) {
            int m = divisors.size();
            long long prime = factors[i];
            for (int j = 0; j + prev < i + 1; j++) {
                for (int k = 0; k < m; k++) {
                    divisors.push_back(divisors[k] * prime);
                }
                prime *= factors[i];
            }
            prev = i + 1;
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}