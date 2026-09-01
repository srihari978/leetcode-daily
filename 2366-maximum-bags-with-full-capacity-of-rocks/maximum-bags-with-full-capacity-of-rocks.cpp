class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> pq;
        for (int i = 0; i < capacity.size(); i++) {
            pq.push_back(capacity[i] - rocks[i]);
        }
        sort(pq.begin(), pq.end());
        int count = 0;
        for (int i = 0; i < pq.size(); i++) {
            int needed = pq[i];
            if (needed > additionalRocks)
                break;
            additionalRocks -= needed;
            count++;
        }
        return count;
    }
};