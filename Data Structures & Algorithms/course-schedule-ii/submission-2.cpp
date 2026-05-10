class Solution {
public:
    // 3-State DFS: 0=Unvisited, 1=Visiting, 2=Visited
    bool hasCycle(vector<vector<int>>& adj, int u, vector<int>& state, vector<int>& order) {
        if (state[u] == 1) return true;  // Cycle detected!
        if (state[u] == 2) return false; // Already processed this node
        
        state[u] = 1; // Mark as "In Stack"
        for (const auto& neighbor : adj[u]) {
            if (hasCycle(adj, neighbor, state, order)) return true;
        }
        
        state[u] = 2; // Mark as "Fully Processed"
        
        /* POST-ORDER ADDITION: 
           We add the node to the list ONLY AFTER all its dependencies 
           are processed. This ensures that if A depends on B, 
           B is pushed before A.
        */
        order.push_back(u); 
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> state(numCourses, 0);
        vector<int> order;

        // Build Adjacency List
        for (const auto& vec : prerequisites) {
            // Logic: vec[0] depends on vec[1] (vec[1] -> vec[0])
            // In your code, you have: adj[vec[0]].push_back(vec[1]);
            // This means your arrows go: Dependent -> Prerequisite
            adj[vec[0]].push_back(vec[1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0) {
                if (hasCycle(adj, i, state, order)) return {}; // Return empty if cycle
            }
        }
        
        // Since your adj is [Dependent -> Prerequisite], 
        // the order you built is already [Prerequisite, ..., Dependent].
        // If your adj was [Prerequisite -> Dependent], you would need to reverse 'order'.
        return order;
    }
};




































/*
class Solution {
public:
    bool hasCycle(vector<vector<int>>& adj, int u, vector<int>& state, vector<int>& order) {
        if (state[u] == 1) return true;
        if (state[u] == 2) return false;

        state[u] = 1;
        for (auto& x : adj[u]) {
            if (hasCycle(adj, x, state, order)) return true;
        }
        state[u] = 2;
        order.push_back(u);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());

        for (auto& vec : prerequisites) {
            adj[vec[0]].push_back(vec[1]);
        }

        vector<int> state(numCourses, 0);
        vector<int> order;
        order.reserve(numCourses);
        for (int i = 0; i<numCourses; ++i) {
            if (state[i] == 0) if (hasCycle(adj, i, state, order)) return {};
        }
        return order;
    }
    
};
*/
