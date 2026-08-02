class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        // int start=0;
        int last = n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                last = i;
                continue;
            }

            if (i == 0 || s[i - 1] == ' ') {
                if (!s.empty())
                    ans += ' ';
                int start = i;
                while (start < last) {
                    ans += s[start];
                    start++;
                }
            }
        }
        ans.erase(0,1);
        return ans;
    }
};