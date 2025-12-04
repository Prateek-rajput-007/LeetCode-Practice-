class Solution {
public:
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> withInserted;
        bool inserted = false;

        // 1) Build new array with newInterval inserted in correct position
        for (auto &it : intervals) {
            // if not yet inserted and current interval's start
            // is >= newInterval's start, insert newInterval first
            if (!inserted && it[0] >= newInterval[0]) {
                withInserted.push_back(newInterval);
                inserted = true;
            }
            withInserted.push_back(it);
        }

        // If newInterval is larger than all existing starts, append at end
        if (!inserted) {
            withInserted.push_back(newInterval);
        }

        // 2) Standard Merge Intervals on withInserted
        vector<vector<int>> merged;
        int n = withInserted.size();
        if (n == 0) return merged;

        int curStart = withInserted[0][0];
        int curEnd   = withInserted[0][1];

        for (int i = 1; i < n; i++) {
            int s = withInserted[i][0];
            int e = withInserted[i][1];

            if (curEnd >= s) {
                // overlap → extend current interval
                curEnd = max(curEnd, e);
            } else {
                // no overlap → push current and start a new one
                merged.push_back({curStart, curEnd});
                curStart = s;
                curEnd   = e;
            }
        }

        // push the last pending interval
        merged.push_back({curStart, curEnd});
        return merged;
    }
};