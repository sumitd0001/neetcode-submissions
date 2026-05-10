class DSU {
    vector<int> parent, rank;
    public : 
    DSU (int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i<size; ++i) parent[i] = i;
    }

    int fi (int x) {
        if (x == parent[x]) return x;
        return parent[x] = fi(parent[x]);
    }

    bool un (int x, int y) {
        int xp = fi(x);
        int yp = fi(y);

        //new merge/connection not happend
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


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size = 0;
        vector<pair<int,int>> res;
        for (const auto& vec : edges) {
            if (vec[0] > size) size = vec[0];
            if (vec[1] > size) size = vec[1];
        }
        DSU obj(size);
        for (const auto& vec : edges) {
            if (!obj.un(vec[0]-1, vec[1]-1)) res.push_back({vec[0], vec[1]});
        }
        int n = res.size();
        return {res[n-1].first, res[n-1].second};
    }
};
