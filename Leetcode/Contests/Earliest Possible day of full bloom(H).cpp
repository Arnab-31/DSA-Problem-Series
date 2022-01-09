//https://leetcode.com/problems/earliest-possible-day-of-full-bloom/


//https://leetcode.com/problems/earliest-possible-day-of-full-bloom/discuss/1676833/C%2B%2B-Largest-Growing-Time-First-with-Illustrations




class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        // growTime larger first
        vector<pair<int, int>> times(n);
        for (int i = 0; i < n; i++) {
            times[i].first = -growTime[i];
            times[i].second = plantTime[i];
        }
        sort(times.begin(), times.end());
        int tot = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            tot = max(tot, cur + times[i].second - times[i].first);
            cur += times[i].second;
        }
        return tot;
    }
};