class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;
        int sum = 0;
        for (int x : weights) {
            low = max(low, x);
            high += x;
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = 0;
            int day = 1;
            for (int a : weights) {
                if (sum + a <= mid) {
                    sum = sum + a;
                } else {
                    day++;
                    sum = a;
                }
            }
            if (day <= days) {
                high = mid-1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};