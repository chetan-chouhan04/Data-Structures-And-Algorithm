class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=1;
        int high=*max_element(arr.begin(),arr.end()) + k;
        int integer=0;
        int ans=0;
        int i=0;
       while(low<=high){
        if(i<n && low==arr[i]){
            i++;
        }
        else{
            integer++;
            ans=low;
            
        }
        low++;
        if(integer==k)
        break;
       }
       return ans;
    }
};