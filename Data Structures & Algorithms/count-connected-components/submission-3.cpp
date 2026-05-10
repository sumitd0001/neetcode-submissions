class UF {
    vector<int> parent_array;
    vector<int> rank_array;
    vector<int> size_array;

public:
    UF(int n) {
        parent_array.resize(n);
        rank_array.resize(n, 0);
        size_array.resize(n, 1);
        // Initially, every node is its own parent (n independent components)
        iota(parent_array.begin(), parent_array.end(), 0); 
    }

    // FIND with Path Compression: 
    // Flattens the tree structure so future finds are O(1)
    int find(int x) {
        if (x == parent_array[x]) return x;
        return parent_array[x] = find(parent_array[x]); 
    }

    // UNION BY RANK: Attach shorter tree under taller tree to keep height minimal
    bool unite_by_rank(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return false; // Already in the same component
        
        if (rank_array[px] > rank_array[py]) {
            parent_array[py] = px;
        } else if (rank_array[py] > rank_array[px]) {
            parent_array[px] = py;
        } else {
            parent_array[py] = px;
            rank_array[px]++; // Only increase rank if heights were equal
        }
        return true;
    }

    // UNION BY SIZE: Attach smaller tree under larger tree
    bool unite_by_size(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return false;

        if (size_array[px] >= size_array[py]) {
            size_array[px] += size_array[py];
            parent_array[py] = px;
        } else {
            size_array[py] += size_array[px];
            parent_array[px] = py;
        }
        return true;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // Optimization: For DSU, you don't even need an adjacency list!
        // You can iterate through 'edges' directly.
        int res = n;
        UF obj(n);

        for (const auto& edge : edges) {
            // Every successful union reduces the number of components by 1
            if (obj.unite_by_size(edge[0], edge[1])) {
                res--;
            }
        }
        return res;
    }
};

/*
class Solution {
public:
    //using dfs
    void dfs(vector<vector<int>>& adj, int u, vector<bool>& visited) {
        visited[u] = true;
        for (const auto& x : adj[u]) if (!visited[x]) dfs(adj, x, visited);
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> visited(n, false);
        int count = 0;
        for (const auto& v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        for (int i = 0; i<n; ++i) {
            if (!visited[i]) {
                dfs(adj, i, visited);
                count++;
            }
        }
        return count;
    }
};
*/
