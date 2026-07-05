class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        //int ans=nums[low];
        while(low < high){
            int mid=(low+high) / 2;
            if(nums[mid] > nums[high]){
                 low=mid+1;
            }
            else{
               high=mid;
            }
            //ans=min(ans,nums[mid]);
        }
        return nums[low];
    }
};