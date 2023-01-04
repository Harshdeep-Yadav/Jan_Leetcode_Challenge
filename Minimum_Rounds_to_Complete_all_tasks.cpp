class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n=tasks.size();
        unordered_map<int,int>mp;
        for(auto it : tasks)
        {
            mp[it]++;
        }
        
        int count=0;
        for(auto it :mp)
        {
            int x=it.second;
            if(x<2)
            {
                return -1;
            }
            count+=(x+2)/3;
        }
        return count;
    }
};