class Solution {
public:
    bool check (unordered_map<int,vector<int>> &adj,int s,int d, vector<bool> &visited) {
        if (s == d ) return true;

        if (visited[s]) return false;

        visited[s] = true;
        
        //explore 
        for(auto &node : adj[s]) {
            if (check(adj,node,d,visited) == true) {
                return true;
            }
        }

        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //adjacency list 
        unordered_map<int, vector<int>> adj;

        for (auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];

            //bidirectional graph 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>  visited(n,false);

        return check(adj,source,destination,visited);

    }
};