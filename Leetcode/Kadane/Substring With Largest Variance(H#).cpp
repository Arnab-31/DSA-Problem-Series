//https://leetcode.com/problems/substring-with-largest-variance/

//Approach - Use the fact that iterating through all 27 characters takes us no time.
//So using every pair of possible character check for highest possible variance using kadane's algo.
//https://leetcode.com/problems/substring-with-largest-variance/discuss/2039178/Weird-Kadane

class Solution {
public:
   int largestVariance(string s) {
    int result = 0;
    unordered_set<char> unique_characters(s.begin(), s.end());

    for (const auto & positive : unique_characters) {
        for (const auto & negative : unique_characters) {
            if (positive == negative) {
                continue;
            }

            int variance = 0;
            bool negative_seen = false;
            bool starts_with_negative = false;

            for (int i = 0; i < s.length(); ++i) {
                const auto c = s[i];
                if (c == positive) {
                    ++variance;
                } else if (c == negative) {
                    // Handles a special case like "baa" where
                    // the first 'b' should be taken into account.
                    if (i == 0) {
                        starts_with_negative = true;
                    }
                    if (variance > 0) {
                        negative_seen = true;
                        --variance;
                    } else {
                        negative_seen = false;
                        variance = 0;
                    }
                }

                result = max(result, negative_seen ? variance : 0);
                    
                if (starts_with_negative) {
                    result = max(result, variance - 1);
                }
            }
        }
    }

    return result;
}
};

