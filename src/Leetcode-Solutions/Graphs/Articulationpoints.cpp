#include <bits/stdc++.h>
using namespace std;


class Solution {
    private:
          int timer = 1;
          void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], vector<int> &mark, vector<int>adj[]){
              vis[node] = 1;
              tin[node] = low[node] = timer;
              timer++;
              int child = 0;
              for (auto it : adj[node]) {
                  if (it == parent) continue;
                  if (!vis[it]) {
                      dfs(it, node, vis, tin, low, mark, adj);
                      low[node] = min(low[node], low[it]);
                      if (low[it] >= tin[node] && parent != -1){
                          mark[node] = 1;
                      }
                      child++;
                  }else {
                      low[node] = min(low[node], tin[it]);
                  }
              }
              
              if (child > 1 && parent == -1){
                  mark[node] = 1;
              }
          };
    
    public:
         vector<int> articulationPaoints(int n, vector<int>adj[]) {
             vector<int> vis(n, 0);
             int tin[n];
             int low[n];
             vector<int> mark(n, 0);
             for (int i = 0; i < n; i++){
                 if(!vis[i]){
                     dfs(i, -1, vis, tin, low, mark, adj);
                 }
             }
             
             vector<int> ans;
             for (int i = 0; i < n; i++){
                 if (mark[i] == 1){
                     ans.push_back(i);
                 }
             }
             
             if (ans.size() == 0) return { -1};
             return ans;
         }
    
};
    
    
    
    
    
    
    
    
//   public:
//     vector<int> articulationPoints(int V, vector<int>adj[]) {
//         // Code here
        
    
//           DisjointSet ds(V);

//           unordered_map<int, int> connected;

//           for(int i = 0; i < V; ++i){
//             for(int j = 1; j < adj[i].size(); ++j){
//                 int weight = adj[i][j];
//                 if (connected.find(weight) == connected.end()){
//                     connected[weight] = i;
//                 } else {
//                     ds.unionByRank(i, connected[weight]);
//                 }
//             }
//           }
       
//        unordered_map<int, int>> FinalPoint;
       
//        for (const auto& entry : FinalPoint) {
//          int vis = entry.first;
//          int index = ds.findUPar(entry.second);
//          [index].push_back(vis);
//        }

//       vector<vector<string>> result;
//       for (const auto& entry : FinalPoint) {
//         int index = entry.first;
//         vector<string> points = entry.second;
//         sort(points.begin(), points.end());
//         points.insert(points.begin(), adj[index][0]); 
//         result.push_back(points);
//       }

//       return result;
//     }
// };