class Solution {
public:
long long total(int mid,vector<int>& piles,int n){
    long long tot=0;
    for(int i=0;i<n;i++){
        tot+=ceil(double(piles[i])/mid);
    }
    return tot;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int high=0;
        for(int i=0;i<n;i++){
            high=max(high,piles[i]);
        }
        if(h==n)
        return high;
        
        int ans=INT_MAX;
        int low=1;
        while(low<=high){
            int mid=(low+high) / 2;
            long long sum=total(mid,piles,n);
            if(sum > h)
            low=mid+1;
            if(sum <= h){
            high=mid-1;
            ans=mid;}
        }
        return ans;
    }
};