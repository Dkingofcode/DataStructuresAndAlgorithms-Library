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
          vector<vector<string>> mergeAccounts (vector<vector<string>>& accounts){
            int n = accounts.size();
            DisjointSet ds(n);

            unordered_map<string, int> emailToIndex;

            for(int i = 0; i < n; ++i){
              for(int j = 1; j < accounts[i]; ++j){
                string email = accounts[i][j];
                if (emailToIndex.find(email) == emailToIndex.end()){
                    emailToIndex[email] = i;
                }else {
                    ds.unionByRank(i, emailToIndex[email]);
                }
              }  
            }
        
        unordered_map<int, vector<string>> indexToEmails;
        for (const auto& entry : emailToIndex){
            string email = entry.first;
            int index = ds.findUPar(entry.second);
            indexToEmails[index].push_back(email);
        }

         vector<vector<string>> result;
         for (const auto& entry : indexToEmails){
            int index = entry.first;
            vector<string> emails = entry.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[i][0]);
            result.push_back(emails);
         }
   return result;
    }
};