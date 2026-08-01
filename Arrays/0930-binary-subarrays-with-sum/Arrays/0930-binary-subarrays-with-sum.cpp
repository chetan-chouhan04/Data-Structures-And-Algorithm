class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int left=0;
        int right=0;
        int count1=0;
        int sum=0;
        int n=nums.size();
        while(right<n){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            count1 += right-left+1;
            right++;
        }
        if(goal==0)
        return count1;
        left=0;
        right=0;
        sum=0;
        int count2=0;
        while(right<n){
            sum+=nums[right];
            while(sum>goal-1){
                sum-=nums[left];
                left++;
            }
            count2+=right-left+1;
            right++;
        }
        return count1 - count2;
    }
};