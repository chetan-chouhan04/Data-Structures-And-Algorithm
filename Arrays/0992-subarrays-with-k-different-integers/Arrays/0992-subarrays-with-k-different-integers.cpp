class Solution {
public:
int atmost(vector<int>& nums, int k){
    int left=0;
    int right=0;
    int count=0;
    unordered_map<int, int> mp;
    int n=nums.size();
    while(right < n){
        mp[nums[right]]++;
        //int s = mp.size();
        while(mp.size()>k){
            mp[nums[left]]--;
            if(mp[nums[left]]==0)
            mp.erase(nums[left]);
            left++;
        }
        count+=right-left+1;
        right++;
    }
    return count;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int count1 = atmost(nums,k);
        int count2 = atmost(nums,k-1);
        return count1-count2;
    }
};