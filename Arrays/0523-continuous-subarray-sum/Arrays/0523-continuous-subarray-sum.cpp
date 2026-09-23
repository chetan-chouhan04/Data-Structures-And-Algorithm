class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int prefix=0;
        unordered_map<int,int> mp;
        mp[0]=0;
        for(int i=1;i<=n;i++){
            prefix+=nums[i-1];
            int rem=prefix%k;
            if(mp.find(rem) != mp.end()){
                if(i - mp[rem] >= 2)
                return true;
            }
            else
            mp[rem]=i;
        }
        return false;
    }
};