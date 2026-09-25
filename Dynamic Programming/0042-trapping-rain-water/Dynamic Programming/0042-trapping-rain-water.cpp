class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax=0;
        int rightmax=0;
        int start=0;
        int n=height.size();
        int end=n-1;
        int total=0;
        while(start<end){
            leftmax=max(leftmax,height[start]);
            rightmax=max(rightmax,height[end]);

            if(leftmax < rightmax){
                total+=leftmax-height[start];
                start++;
            }
            else{
                total+=rightmax-height[end];
                end--;
            }
        }
        return total;
    }
};