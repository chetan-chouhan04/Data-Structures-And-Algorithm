class Solution {
public:
    int subarraysum(vector<int>& nums, int sum) {
        int subarray=1;
        int currsum=0;
        for(int i=0;i<nums.size();i++){
            if(currsum + nums[i] <= sum)
            currsum+=nums[i];
            else{
                subarray+=1;
                currsum=nums[i];
            }
        }
        return subarray;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while (low <= high) {
            int mid = (low + high) / 2;
            int subarray = subarraysum(nums, mid);
            if (subarray > k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};