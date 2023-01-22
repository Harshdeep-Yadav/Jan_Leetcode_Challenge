class Solution {
public:
     
    void func(int ind,string s,vector<vector<string>>&res,vector<string>&paths)
    {   
        if(ind==s.size())
        {
            res.push_back(paths);
            return;
        }
        
        for(int i=ind;i<s.size();++i)
        {
            if(isPalindrome(s,ind,i)){
                paths.push_back(s.substr(ind,i-ind+1));
                func(i+1,s,res,paths);
                paths.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s,int start,int end)
    {
       while(start<=end)
       {
           if(s[start++]!=s[end--])
               return false;
       }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
     vector<vector<string>>res;
        vector<string> paths;
        func(0,s,res,paths);
        return res;
    }
   
};