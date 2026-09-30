class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxlen=0;
        int left=0;
        int right=0;
        unordered_map<char,int> mp;
        while(right < n){
            if(mp.find(s[right]) != mp.end()){
                left=max(mp[s[right]]+1 , left);

            }
            mp[s[right]] = right;
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};