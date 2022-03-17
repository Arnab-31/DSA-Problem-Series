//https://leetcode.com/problems/construct-string-with-repeat-limit/discuss/1784718/C%2B%2B-Greedy-%2B-Counting-O(N)-Time-O(1)-space

/* Store frequency of characters in int cnt[26].

We pick characters in batches. In each batch, we pick the first character from z to a whose cnt is positive with the following caveats:

If the current character is the same as the one used in the previous batch, we need to skip it.
On top of case 1, if the cnt of the character used in the previous batch is positive, then we can only fill a single character in this batch.
*/

// Time: O(N)
// Space: O(1)

class Solution {
public:
    string repeatLimitedString(string s, int limit) {
        int cnt[26] = {};
        string ans;
        for (char c : s) cnt[c - 'a']++;
        while (true) {
            int i = 25;
            bool onlyOne = false;
            for (; i >= 0; --i) {
                if (ans.size() && i == ans.back() - 'a' && cnt[i]) { // the character of our last batch still has some count left, so we only insert a single character in this batch
                    onlyOne = true;
                    continue;
                }
                if (cnt[i]) break; // found a character with positive count, fill with this character
            }
            if (i == -1) break; // no more characters to fill, break;
            int fill = onlyOne ? 1 : min(cnt[i], limit);
            cnt[i] -= fill;
            while (fill--) ans += 'a' + i;
        }
        return ans;
    }
};