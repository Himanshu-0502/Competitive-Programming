#include <bits/stdc++.h>
using namespace std;

int Number(int a, int b) {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    return (a + rng() % (b - a + 1));
}

struct Testcase {

};

Testcase generate() {
    Testcase T;
    
    return T;
}

int participant(Testcase T) {

}

int judge(Testcase T) {
    
}

void print(Testcase T) {

}

void output(int ans) {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; i++) {
        Testcase T = generate();

        int P = participant(T);
        int J = judge(T);

        if (P == J) {
            cout << "Passed Testcase: " << i << "\n";
        } else {
            cout << "Failed Testcase: " << i << "\n";

            cout << "Input" << "\n";
            print(T);

            cout << "Your Output" << "\n";
            output(P);

            cout << "Judy Output" << "\n";
            output(J);
            exit(0);
        }
    }

    return 0;
}