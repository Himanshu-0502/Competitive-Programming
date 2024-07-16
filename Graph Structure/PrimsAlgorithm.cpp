#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<int>> points(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin>>points[i][0]>>points[i][1];
    }
    vector<vector<int>> dist(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
        }
    }
    vector<bool> mark(n);
    vector<vector<int>> edge(n,{INT_MAX,-1});
    edge[0]={0,-1};
    vector<pair<int,int>> mst;
    int cost=0;
    for(int i=0;i<n;i++){
        int v=find(mark.begin(),mark.end(),false)-mark.begin();
        for(int j=0;j<n;j++){
            if(mark[j]) continue;
            if(edge[j][0]<edge[v][0]) v=j;
        }
        if(edge[v][0]==INT_MAX) break;
        mark[v]=true;
        cost+=edge[v][0];
        if(edge[v][1]!=-1) mst.push_back({v,edge[v][1]});
        for(int j=0;j<n;j++){
            if(dist[v][j]<edge[j][0]){
                edge[j]={dist[v][j],v};
            }
        }
    }
    cout<<cost<<"\n";
    for(auto [u,v]:mst){
        cout<<u<<" "<<v<<"\n";
    }
    return 0;
}