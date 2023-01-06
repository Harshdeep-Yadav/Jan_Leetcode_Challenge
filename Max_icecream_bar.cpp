class Solution {
public:
    int maxIceCream(vector<int>& c, int coins) {
        int n=c.size();
        int count=0;
        sort(c.begin(),c.end());
        for(int i=0;i<n;i++)
        {
            if(c[i]>coins)
                break;
            coins=coins-c[i];
            count++;
            
        }
        return count;
    }
};