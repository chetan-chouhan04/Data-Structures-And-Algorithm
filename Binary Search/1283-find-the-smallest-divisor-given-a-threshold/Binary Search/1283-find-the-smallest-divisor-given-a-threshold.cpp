class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans=0;
        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += ceil((double)nums[i] / mid);
            }
            if (sum <= threshold) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};