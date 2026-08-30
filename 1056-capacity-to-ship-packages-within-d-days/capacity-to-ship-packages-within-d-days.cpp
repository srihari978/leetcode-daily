class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int day = 0;
        int low = 0;
        int high = 0;
        for (int i : weights) {
            low = max(i, low);
            high += i;
        }
        while (low < high) {
            int mid = low + (high - low) / 2;
            int sum = 0;
            int day = 1;
            for (int i : weights) {
                if (sum + i <= mid) {
                    sum += i;
                } else {
                    day++;
                    sum = i;
                }
            }
            if (day <= days) {
                high=mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};