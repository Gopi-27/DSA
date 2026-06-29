#include<bits/stdc++.h>
using namespace std;
// Binary Lifting
// Time Complexity: O(nlogn) for preprocessing and O(logn) for each query
// Space Complexity: O(nlogn)

// Main Idea:
// We can use binary lifting to find the k-th ancestor of a node in a tree.
// We can precompute the 2^i-th ancestor for each node and store it in a table.
// Then, to find the k-th ancestor of a node, we can represent k in binary 
// and use the precomputed table to jump to the appropriate ancestors.

// The Root node is 0  always and the tree is 0-indexed.
// Example:
// Input:
// 7
// 0 1                              0
// 0 2                             / \
// 1 3                            1   2
// 1 4                            / \ / \
// 2 5                           3  4 5  6
// 2 6

int main(){
// number of nodes;
    int n;
    cin >> n;
// edges list
    vector<vector<int>> Adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    vector<vector<int>> Par(n, vector<int>(20, -1));
    // First ancestor of each node is its parent

    
}