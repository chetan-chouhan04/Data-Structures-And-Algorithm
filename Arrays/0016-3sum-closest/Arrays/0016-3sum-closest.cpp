class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int close=INT_MAX;
        int min_sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target - sum) < close){
                    min_sum = sum;
                    close = abs(target - sum);
                }
                if(sum < target)
                j++;
                else
                k--;
            }
        }
        return min_sum;
    }
};