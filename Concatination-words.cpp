class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
       unordered_set<string>set;
        for(auto it:words){
            set.insert(it);
        }
        vector<string>ans;
        for(auto it:words){
            int n=it.size();
            vector<int>dp(n+1,0);
            dp[0]=1;
            for(int i=0;i<n;i++){
                if(!dp[i]) continue;
                for(int j=i+1;j<=n;j++){
                   if(j-i<n&&set.count(it.substr(i,j-i))){
                       dp[j]=1;
                   }
                }
                if(dp[n]){
                    ans.push_back(it);
                    break;
                }
            }
        }
        return ans ;
    }
};