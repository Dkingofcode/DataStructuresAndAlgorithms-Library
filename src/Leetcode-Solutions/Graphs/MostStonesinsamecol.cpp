// Most Stones Removed with Same Row or Column


#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
    public:
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1);
            for(int i = 0;  i <= n; i++){
                parent[i] = i;
                size[i] = i;
            }
        }
        
        int findUPar(int node) {
            if(node == parent[node]) return node;
                return parent[node] = findUPar(parent[node]);   
        }
        
        void unionByRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = rank[ulp_v];
            }

            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = rank[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }


        void unionBySize(int u, int v) {
           int ulp_u = findUPar(u);
           int ulp_v = findUPar(v);
           if(ulp_u == ulp_v) return;
           if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+= size[ulp_u];
           }else{
             parent[ulp_v] = ulp_u;
             size[ulp_u] += size[ulp_v];
           }
        }
};

class Solution {
    public:

    int removeStones(vector<vector<int>>& stones){
        int n = stones.size();

        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1];
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int count = 0;
        for (auto it : stoneNodes) {
            if(ds.findUPar(it.first) == it.first){
                count++;
            }
        }

        return n - count;
    }
};