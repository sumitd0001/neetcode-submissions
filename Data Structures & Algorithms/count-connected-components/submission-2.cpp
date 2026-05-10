class UF {
    vector<int> parent_array;
    vector<int> rank_array;
    vector<int> size_array;

    public : 
        UF (int n) {
            parent_array.resize(n);
            rank_array.resize(n, 0);
            size_array.resize(n, 1);
            for (int i = 0; i < n; ++i ) parent_array[i] = i;
        }
    
    public : 

    int find(int x) {
        if (x == parent_array[x]) return x;
        return parent_array[x] = find(parent_array[x]);
    }

    bool unite_by_rank (int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return false;
        if (rank_array[px] > rank_array[py]) {
            parent_array[py] = px;
        }
        else if (rank_array[py] > rank_array[px]) {
            parent_array[px] = py;
        }
        else {
            parent_array[py] = px;
            rank_array[px]++;
        }
        return true;
    }

    bool unite_by_size (int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return false;

        if (size_array[px] >= size_array[py]) {
            size_array[px] = size_array[px] + size_array[py];
            parent_array[py] = px;
        }
        else {
            size_array[py] = size_array[py] + size_array[px];
            parent_array[px] = py;
        }
        return true;
    }
};


class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        int res = n;
        for (const auto& vec : edges) {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        
        UF* obj = new UF(n);

        for (int i = 0; i<n; ++i) {
            for (const auto& u : adj[i]) {
                //if (obj->unite_by_rank(i, u)) res--;
                if (obj->unite_by_size(i, u)) res--;
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
