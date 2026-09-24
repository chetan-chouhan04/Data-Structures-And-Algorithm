class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int lp=0;
        int rp=n-1;
        int mw=0;
        while(lp < rp){
            int area = (rp-lp) * min(height[lp],height[rp]);
            mw=max(mw,area);
            height[lp] < height[rp] ? lp++ : rp-- ;
        }

        return mw;
    }
};