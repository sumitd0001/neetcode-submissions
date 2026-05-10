class DSU {
    vector<int> parent, rank;
    int size;
    public : 
    DSU (int s) {
        size = s;
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i<s; ++i) parent[i] = i;
    }

    int fi (int x) {
        if (x == parent[x]) return x;
        return parent[x] = fi(parent[x]);
    }

    bool un (int x, int y) {
        int xp = fi(x);
        int yp = fi(y);

        if (xp == yp) return false;

        if (rank[xp] > rank[yp]) {
            parent[yp] = xp;
        }
        else if (rank[xp] < rank[yp]) {
            parent[xp] = yp;
        }
        else {
            parent[yp] = xp;
            rank[xp]++;
        }
        return true;
    }

};


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;
        DSU obj(n);
        for (const auto& edge : edges) if (!obj.un(edge[0], edge[1])) return false;
        return true;
    }
};

/*
class DSU {
    vector<int> parent, rank;
    public : 
        DSU (int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i<n; ++i) parent[i] = i;
        }

        int fi (int x) {
            if (x == parent[x]) return x;
            return parent[x] = fi(parent[x]);
        }

        bool un (int x, int y) {
            int xp = fi(x);
            int yp = fi(y);

            if (xp == yp) return false;

            if (rank[xp] > rank[yp]) parent[yp] = xp;
            else if (rank[yp] > rank[xp]) parent[xp] = yp;
            else {
                parent[yp] = xp;
                rank[xp]++;
            }
            return true;
        }
};
*/

/*
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        //In an undirected connected graph , if there are n nodes, then there must be only n-1 edges
        //otherwise there is a cycle
        if (edges.size() != n-1) return false;
        
        DSU obj(n);
        for (const auto& vec : edges) if (!obj.un(vec[0], vec[1])) return false;
        return true;
    }
};
*/
