class Solution {
public:
    int maxScore(vector<pair<int,int>>agesScore){
        int n = agesScore.size();
        int sum=0;
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            dp[i]=agesScore[i].second;
            sum=max(sum,dp[i]);
        }
        
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(agesScore[i].second>=agesScore[j].second)
                    dp[i]=max(dp[i],agesScore[i].second+dp[j]);
            }
        sum=max(sum,dp[i]);
        }
        return sum;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>agesScore;
        for(int i=0;i<scores.size();i++){
            agesScore.push_back({ages[i],scores[i]});
        }
        sort(agesScore.begin(),agesScore.end());
        return maxScore(agesScore);
    }
};