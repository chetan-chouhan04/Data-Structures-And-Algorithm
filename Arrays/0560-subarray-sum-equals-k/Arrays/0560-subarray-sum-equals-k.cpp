class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefixsum=0;
        int count=0;
        unordered_map<int, int> mp;
        mp[0]=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            prefixsum += nums[i];
            int ele = prefixsum-k;
            count+=mp[ele];
            mp[prefixsum]++;
        }
        return count;
    }
};