class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int l=0,r=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='L')l++;
            else if(moves[i]=='R')r++;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(l>=r){
               if(moves[i]=='_'||moves[i]=='L'){
                 ans--;
               }else
                ans++;
               
               
            }else{
               if(moves[i]=='_'||moves[i]=='R'){
                ans++;
               }
               else{
                ans--;
               }
            }
        }
        return abs(ans);
    }
};