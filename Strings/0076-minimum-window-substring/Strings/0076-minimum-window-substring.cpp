class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {0};
        int n = s.size();
        int m = t.size();
        int l = 0;
        int r = 0;
        int minlen = 1e9;
        int start = -1;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }
        while (r < s.size()) {
            if (hash[s[r]] > 0)
                cnt++;
            hash[s[r]]--;
            while (cnt == m) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    start = l;
                }
                hash[(unsigned char)s[l]]++;
                
                if (hash[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        if (start == -1)
            return "";
        return s.substr(start, minlen);
    }
};