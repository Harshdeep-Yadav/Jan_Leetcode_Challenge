class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();

        int current = 0;

        int strid = 0;

        int totfuel = accumulate(gas.begin(), gas.end(), 0);

        int totcost = accumulate(cost.begin(), cost.end(), 0);
        // cout<<totcost;
        if (totfuel < totcost)
            return -1;

        for (int i = 0; i < n; i++)
        {
            current += gas[i] - cost[i];
            if (current < 0)
            {
                strid = i + 1;
                current = 0;
            }
        }
        return strid;
    }
};