class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
         int n = s.length();
         for(int i=0;i<n;i++){
            char ch = s[0];
            s = s.substr(1)+ch;
            if(s==goal)return true;
         }
         return false;
    //    if(s.length()!=goal.length())return false;
    //    string temp = s + s;
    //    return  (temp.find(goal)!=string::npos);
    }
};

