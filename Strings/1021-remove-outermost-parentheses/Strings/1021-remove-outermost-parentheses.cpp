class Solution {
public:
    string removeOuterParentheses(string s) {
        int open=0;
        int close=0;
        int n=s.size();
        int start=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='(')
            open++;
            else if(s[i]==')')
            close++;
            if(open-close ==0){
                start=start+1;
                while(start!=i){
                    ans+=s[start];
                    start++;
                }
                start=i+1;
                open=0;
                close=0;
            }

        }
        return ans;
    }
};