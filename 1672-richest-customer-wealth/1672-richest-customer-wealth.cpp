class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = INT_MIN;
        for(auto i: accounts) {
            int sum=0;
            for(auto j: i) {
                sum+=j;
            }
            max_wealth = max(max_wealth,sum);
        }
        return max_wealth;
    }
};