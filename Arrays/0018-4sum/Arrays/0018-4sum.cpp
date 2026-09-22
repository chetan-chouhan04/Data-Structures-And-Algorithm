class Solution {
public:
    void threesum(vector<int>& nums, int target, int a,
                  vector<vector<int>>& ans) {
        int n = nums.size();
        for (int i = a+1; i < n; i++) {
            if (i > a+1 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                long long sum = 1LL * nums[a] + nums[i] + nums[j] + nums[k];
                if (sum < target)
                    j++;
                else if (sum > target)
                    k--;
                else {
                    vector<int> temp = {nums[a], nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            threesum(nums, target, i, ans);
        }
        return ans;
    }
};