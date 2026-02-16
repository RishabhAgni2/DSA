class Solution {
private:
   int countset(int x){
      int cnt =0;
      while(x>1){
        cnt += x&1;
        x = x>>1;
      }
      if(x==1)cnt += 1;
      return cnt;
   }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            ans.push_back(countset(i));
        }
        return ans;
    }
};