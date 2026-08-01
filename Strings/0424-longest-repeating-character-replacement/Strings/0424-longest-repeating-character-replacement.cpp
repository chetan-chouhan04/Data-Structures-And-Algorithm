class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;
        int maxf=0;
        int maxlen=0;
        int hash[26]={0};
        int n=s.size();
        while(right<n){
            hash[s[right] - 'A']++;
            maxf=max(maxf, hash[s[right]-'A']);
            int changes = right-left+1 - maxf;
            if(changes > k){
                hash[s[left]-'A']--;
                maxf=0;
                left++;
            }
            if(changes <= k){
                maxlen=max(maxlen, right-left+1);
                
            }
            right++;
        }
        return maxlen;
    }
};