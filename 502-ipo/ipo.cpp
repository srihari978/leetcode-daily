class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        // Sort indices based on required capital
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return capital[a] < capital[b];
        });

        priority_queue<int> maxProfitHeap;
        int idx = 0;

        while (k > 0) {
            // Push profits of all projects affordable with current capital
            while (idx < n && capital[indices[idx]] <= w) {
                maxProfitHeap.push(profits[indices[idx]]);
                idx++;
            }

            if (maxProfitHeap.empty()) break;

            w += maxProfitHeap.top();
            maxProfitHeap.pop();
            k--;
        }

        return w;
    }
};