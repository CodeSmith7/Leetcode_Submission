//Approch 1 : 
// class Solution {
// public:
//     void DFS(int ancestor,unordered_map<int, vector<int>>& adj, int currNode, vector<vector<int>>& result) {
//         for (int &ngbr : adj[currNode]) {
//             if (result[ngbr].empty() || result[ngbr].back() != ancestor) {
//                 result[ngbr].push_back(ancestor);
//                 DFS(ancestor, adj, ngbr, result);
//             }
//         }
//     }
    


//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> result(n);
//         unordered_map<int, vector<int> > adj;

//         for (auto &vec: edges) {
//             int u = vec[0];
//             int v = vec[1];

//             //unidirectional graph 
//             adj[u].push_back(v);
//         }

//         for (int i = 0; i < n; i++) {
//             int ancestor = i;
//             DFS(ancestor, adj, i, result);
//         }

//         return result;
        
//     }
// };


//Approach 2 : by reversing the edges 
class Solution {
public:
    void DFS(int u,unordered_map<int, vector<int>>& adj, vector<bool>& visited) { 
        visited[u] = true;

        for (int &v : adj[u]) {
            if (visited[v] == false) {
                DFS(v,adj,visited);
            }
        }
        
    }
    


    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result;
        unordered_map<int, vector<int> > adj;

        for (auto &vec: edges) {
            int u = vec[0];
            int v = vec[1];

            //unidirectional graph 
            adj[v].push_back(u);
        }

        for (int u = 0; u < n; u++) {
            vector<int> ancestor;
            vector<bool> visited(n,false);

            DFS(u,adj,visited);

            for (int i = 0; i < n; i++) {
                if (i == u) continue;

                if (visited[i] == true) {
                    ancestor.push_back(i);
                }
            }
            result.push_back(ancestor);
        }

        return result;
        
    }
};