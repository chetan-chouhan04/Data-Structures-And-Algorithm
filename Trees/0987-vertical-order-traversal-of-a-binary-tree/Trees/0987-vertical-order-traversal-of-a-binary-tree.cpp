#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};

        // map: column -> list of (row, value)
        map<int, vector<pair<int,int>>> mp;
        // BFS queue of (node, row, col)
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        int minCol = 0, maxCol = 0;

        while (!q.empty()) {
            auto [node, row, col] = q.front();
            q.pop();

            mp[col].push_back({row, node->val});
            minCol = min(minCol, col);
            maxCol = max(maxCol, col);

            if (node->left)  q.push({node->left,  row + 1, col - 1});
            if (node->right) q.push({node->right, row + 1, col + 1});
        }

        vector<vector<int>> result;
        for (int c = minCol; c <= maxCol; ++c) {
            auto &vec = mp[c];
            // sort by row, then value
            sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int,int>& b){
                if (a.first != b.first) return a.first < b.first; // smaller row first
                return a.second < b.second; // smaller value first
            });

            vector<int> colVals;
            colVals.reserve(vec.size());
            for (auto &p : vec) colVals.push_back(p.second);
            result.push_back(move(colVals));
        }

        return result;
    }
};
