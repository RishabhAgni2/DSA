class Solution {
private:
   void dfs(int i,vector<int> &vis,vector<vector<int>> &adjlis){
       vis[i]=1;
       for(auto it:adjlis[i]){
          if(!vis[it]){
            dfs(it,vis,adjlis);
          }
       }
   }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adjlis(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjlis[i].push_back(j);
                    adjlis[j].push_back(i);
                }
            }
        }
        int cnt =0;
        vector<int> vis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adjlis);
            }
        }
        return cnt;
    }
};