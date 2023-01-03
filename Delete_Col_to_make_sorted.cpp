class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int k=strs[0].size();
        int count=0;
        for(int c=0;c<k;c++) // traverse columns
        {
            for(int r=1;r<strs.size();r++) // traverse rows
            {
                if(strs[r][c]<strs[r-1][c])
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};