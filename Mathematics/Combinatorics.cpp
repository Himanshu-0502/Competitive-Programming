#include <bits/stdc++.h>
using namespace std;

class Combinatorics {
    public:
    vector<long long> factorial;
    vector<long long> inverse;
    vector<long long> inverseFactorial;
    
    Combinatorics(int n, int mod) {
        factorial.assign(n + 1, 1);
        inverse.assign(n + 1, 1);
        inverseFactorial.assign(n + 1, 1);

        for (int i = 2; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % mod;
            inverse[i] = mod - (inverse[mod % i] * (mod / i)) % mod;
            inverseFactorial[i] = (inverseFactorial[i - 1] * inverse[i]) % mod;
        }
    }

    long long exp(long long a, long long b, long long mod) {
        long long ans = 1;
        while (b > 0) {
            if (b & 1) {
                ans = (ans * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }

    long long inv(long long n, long long mod) {
        return exp(n, mod - 2, mod);
    }

    long long nCr(int n, int r, int mod) {
        if (r > n || r < 0) {
            return 0;
        }

        long long ans = factorial[n];
        ans = (ans * inverseFactorial[r]) % mod;
        ans = (ans * inverseFactorial[n - r]) % mod;
        return ans;
    }

    long long nPr(int n, int r, int mod) {
        if (r > n || r < 0) {
            return 0;
        }

        long long ans = factorial[n];
        ans = (ans * inverseFactorial[n - r]) % mod;
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}