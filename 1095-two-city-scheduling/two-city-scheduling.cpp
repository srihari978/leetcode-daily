class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

        sort(costs.begin(), costs.end(),
             [](vector<int>& a, vector<int>& b) {
                 return (a[1] - a[0]) < (b[1] - b[0]);
             });

        int n = costs.size() / 2;
        int ans = 0;

        // First n people -> B
        for (int i = 0; i < n; i++)
            ans += costs[i][1];

        // Remaining -> A
        for (int i = n; i < costs.size(); i++)
            ans += costs[i][0];

        return ans;
    }
};