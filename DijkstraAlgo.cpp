#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> Dijkstra(int src,vector<vector<pair<int,int>>>& Adj,int n){
    vector<int>Dis(n,1e9);
    Dis[src] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src});
    while(!pq.empty()){
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(Dis[u] < w)continue;
        for(auto e : Adj[u]){
            int v = e.first;
            int wt = e.second;
            if(Dis[v] > w + wt){
                Dis[v] = w + wt;
                pq.push({w + wt,v});
            }
        }
    }
    for(int i = 0; i < n; i++)if(Dis[i] == 1e9)Dis[i] = -1;
    return Dis;
}
int main(){
    int n;
    cout << "Enter Number of Vertices\n";
    cin >> n;
    vector<vector<pair<int,int>>>Adj(n);
    int ecnt;
    cout << "Enter No.of Edges\n";
    cin >> ecnt;
    while(ecnt--){
        cout << "Enter u -> v -> w\n";
        int u,v,w;
        cin >> u >> v >> w;
        Adj[u].push_back({v,w});
        Adj[v].push_back({u,w});

    }
    vector<int>Dis = Dijkstra(0,Adj,n);
    for(int i = 0; i < n; i++)cout << Dis[i] << " ";
}
