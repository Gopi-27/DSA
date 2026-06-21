#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (DSU) or Union-Find data structure implementation
// The main aim is to fix one parent for each components 
class DisjointSet{
    // rank[i] = size of the component whose ultimate parent is i
    // parent[i] = parent of node i
    // Initially, each node is its own parent (self loop)
    // The rank is initialized to 0 for all nodes
    vector<int>rank,parent;
public :
    DisjointSet(int n){
        // Resize the rank and parent vectors to accommodate n nodes (1-based indexing)
        rank.resize(n + 1);
        // Initialize the parent of each node to itself
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++)parent[i] = i;
    }

    int findParent(int u){
        // If the parent of u is itself, then u is the ultimate parent
        if(parent[u] == u)return u;
        // Path compression optimization: make the parent of u point directly to the ultimate parent
        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u,int v){
        // Find the ultimate parents of u and v
        int ultimatePar_u = findParent(u);
        int ultimatePar_v = findParent(v);
        // If they are already in the same component, do nothing
        if(ultimatePar_u == ultimatePar_v)return ;
        // Union by rank optimization: attach the smaller tree under the larger tree
        if(rank[ultimatePar_u] < rank[ultimatePar_v]){
            parent[ultimatePar_u] = ultimatePar_v;
        }else if(rank[ultimatePar_u] > rank[ultimatePar_v]){
            parent[ultimatePar_v] = ultimatePar_u;
        }else{
            // If ranks are equal, attach one tree under the other and increment the rank
            parent[ultimatePar_u] = ultimatePar_v;
            rank[ultimatePar_u]++;
        }
    }
};
int main(){
    // Create a DisjointSet with 5 elements (1 to 5)
    DisjointSet ds(5);
    // Add edges to the disjoint set
    ds.unionByRank(1,2);
    ds.unionByRank(3,4);

    // Check if nodes 1 and 4 are in the same component
    if(ds.findParent(1) == ds.findParent(4)){
        cout << "Same\n";
    }else{
        cout << "NO\n";
    }
    // Union nodes 1 and 4
    ds.unionByRank(1,4);
    // Check again if nodes 1 and 4 are in the same component after the union
    if(ds.findParent(1) == ds.findParent(4)){
        cout << "Same\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}
