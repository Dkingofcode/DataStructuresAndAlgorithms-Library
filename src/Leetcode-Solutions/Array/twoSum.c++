#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Brute Force solution
    vector<int> twoSum(vector<int> numbers, int target) {
        vector<int> ans;
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[j] == target - numbers[i]) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans; // return empty vector if no solution is found
    }
};

vector<pair<int, int>> twoSumHash(vector<int> numbers, int target){
    unordered_map<int, int> map;
    vector<pair<int, int>> ans; 

    for(int i = 0; i < numbers.size(); i++){
        int complement = target - numbers[i];
        if(map[complement]){
           ans.emplace_back(map[complement], i);
        } 
        map[numbers[i]] = i;
    }
    return ans;
}

int main() {
    Solution solution;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(numbers, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two sum solution" << endl;
    }

    return 0;
}
