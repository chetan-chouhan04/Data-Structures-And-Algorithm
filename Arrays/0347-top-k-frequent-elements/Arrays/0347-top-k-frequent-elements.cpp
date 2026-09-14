class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> vec;
        for(auto &[key,value] : mp){
            vec.push_back({value,key});
        }
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};