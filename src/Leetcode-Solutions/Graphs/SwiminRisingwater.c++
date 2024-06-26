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
};



class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
         int n = grid.size();

         DisjointSet ds(n * n);
         vector<int> directions = {-1, 0, 1, 0, -1};

          auto index = [n](int x, int y) { return x * n + y;};

           vector<pair<int, pair<int, int>>> cells;
          for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                       cells.push_back({grid[i][j], {i, j}});
            
                        }
                    }
                
                sort(cells.begin(), cells.end());

           for(auto cell : cells){
              int height = cell.first;
              int x = cell.second.first;
              int y = cell.second.second;
              for (int k = 0; k < 4; ++k){
                int ni = x + directions[k];
                int nj = y + directions[k + 1];
                if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] <= height){
                    ds.unionBySize(index(x, y), index(ni, nj));
                 }
                }

                if(ds.findUPar(0) == ds.findUPar(n * n - 1)) {
                    return height;
                }
              }

        return -1;
    }
};