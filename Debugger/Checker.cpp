#include <bits/stdc++.h>
using namespace std;
long long Number(long long a,long long b){
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    return (a+rng()%(b-a+1));
}
class Testcase{
    public:
    
};
Testcase Generate(){
    Testcase T;
    
    return T;
}
int Participant(Testcase T){
    
}
int Judge(Testcase T){
    
}
void Print(Testcase T){
    
}
void Output(int ans){

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++){
        Testcase T=Generate();
        int P=Participant(T);
        int J=Judge(T);
        if(P==J){
            cout<<"Passed Testcase: "<<i<<"\n";
        }
        else{
            cout<<"Failed Testcase: "<<i<<"\n";
            cout<<"Input: ";
            Print(T);
            cout<<"Expected: ";
            Output(J);
            cout<<"Found: ";
            Output(P);
            return 0;
        }
    }
    cout<<"Successfully Passed All Testcases";
    return 0;
}