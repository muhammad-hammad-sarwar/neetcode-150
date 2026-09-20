class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0, prevEnd = intervals[0][1], n = intervals.size();

        for(int i = 1; i < n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start < prevEnd) {
                ans++;
                prevEnd = min(prevEnd, end);
            } else {
                prevEnd = end;
            }
        }

        return ans;
    }
};