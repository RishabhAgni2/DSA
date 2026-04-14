class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char ,int> map;
        map['I']=1;
        map['V']=5;
        map['X']=10;
        map['L']=50;
        map['C']=100;
        map['D']=500;
        map['M']=1000;
        int ans=0;
        int n = s.length();
        for(int i=0;i<n-1;i++){
            int curr = map[s[i]];
            int next = map[s[i+1]];
            if(next>curr){
                ans -= curr;
            }else{
                ans += curr;
            }
        }
        ans += map[s[n-1]];
        return ans;
    }
};