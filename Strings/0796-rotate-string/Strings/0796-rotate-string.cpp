class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
            for(int i=0;i<n;i++){
                string temp=s;
                if(temp[i]==goal[0]){
                    string ele=temp.substr(0,i);
                    temp.erase(0,i);
                    temp+=ele;
                    if(temp==goal)
                    return true;
                }
            }
            return false;
        
    }
};