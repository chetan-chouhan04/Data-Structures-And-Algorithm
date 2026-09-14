class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        int n=strs.size();
        for(auto& x : strs){
            string key=x;
            sort(x.begin(),x.end());
            mp[x].push_back(key);
        }
        vector<vector<string>> ans;
        for(auto &[key,vec] : mp){
            ans.push_back(vec);
        }
        return ans;
    }
};