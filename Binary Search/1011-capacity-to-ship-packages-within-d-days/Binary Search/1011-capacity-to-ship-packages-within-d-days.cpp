class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low= *max_element(weights.begin(),weights.end());
        int high=0;
        for(int i=0;i<n;i++){
            high+=weights[i];
        }
        while(low<=high){
            int mid=(low+high) / 2;
            int sum=0;
            int day=1;
            for(int i=0;i<n;i++){
                if(weights[i]+sum <= mid){
                    sum+=weights[i];
                }
                else if(weights[i]+sum > mid){
                    day++;
                    sum=weights[i];
                }
            }
            if(day <= days)
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
};