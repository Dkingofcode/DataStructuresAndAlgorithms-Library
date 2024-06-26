#include <bits/stdc++.h>
using namespace std;


class DisjointSet {
    vector<int> rank, parent, size;
    public:
       DisjointSet(int n) {
         rank.resize(n + 1, 0);
         parent.resize(n + 1);
         size.resize(n + 1);
         for (int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
         }
       }

       int findUPar(int node) {
         if(node == parent[node]) return node;
         return parent[node] = findUPar(parent[node]);
       }

       void unionByRank(int u, int v) {
         int ulp_u = findUPar(u);
         int ulp_v = findUPar(v);
         if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
         }

         else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
         }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
         }
       }

       void unionBySize(int u, int v){
         int ulp_u = findUPar(u);
         int ulp_v = findUPar(v);
         if (ulp_u == ulp_v) return;
         if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
         }else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
         }
       }

        int getSize(int node) {
         return size[findUPar(node)];
       }



};







class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        vector<int> directions = {-1, 0, 1, 0, -1};

        auto index = [n](int x, int y) { return x * n + y; };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + directions[k];
                        int nj = j + directions[k + 1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                            ds.unionBySize(index(i, j), index(ni, nj));
                        }
                    }
                }
            }
        }

        int maxIslandSize = 0;
        for (int i = 0; i < n * n; ++i) {
            if (ds.findUPar(i) == i) {
                maxIslandSize = max(maxIslandSize, ds.getSize(i));
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> connectedComponents;
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + directions[k];
                        int nj = j + directions[k + 1];
                        if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] == 1) {
                            connectedComponents.insert(ds.findUPar(index(ni, nj)));
                        }
                    }

                    int newSize = 1;  // Convert this 0 to 1
                    for (int comp : connectedComponents) {
                        newSize += ds.getSize(comp);
                    }
                    maxIslandSize = max(maxIslandSize, newSize);
                }
            }
        }

        return maxIslandSize;
    }
};