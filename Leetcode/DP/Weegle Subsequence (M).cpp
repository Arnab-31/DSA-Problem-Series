//https://leetcode.com/problems/wiggle-subsequence/

/*up[i] refers to the length of the longest wiggle subsequence obtained so far considering i^{th}i 
th
  element as the last element of the wiggle subsequence and ending with a rising wiggle.

Similarly, down[i]down[i] refers to the length of the longest wiggle subsequence obtained so far considering i^{th}i 
th
  element as the last element of the wiggle subsequence and ending with a falling wiggle.

up[i]up[i] will be updated every time we find a rising wiggle ending with the i^{th}i 
th
  element. Now, to find up[i]up[i], we need to consider the maximum out of all the previous wiggle subsequences ending with a falling wiggle i.e. down[j]down[j], for every j<i and nums[i]>nums[j]. Similarly, down[i]down[i] will be updated.
*/


class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int n = a.size(), ans = 1; 
        if(n == 0) return 0;
        vector<int> dp1(n,1), dp2(n,1);
        for(int i = 1 ; i < n ; i++) {
        	for(int j = i-1 ; j >= 0 ; j--) {
        		if(a[i] > a[j] and dp1[i] < 1 + dp2[j]) dp1[i] = 1 + dp2[j];
        		if(a[i] < a[j] and dp2[i] < 1 + dp1[j]) dp2[i] = 1 + dp1[j];
        	}

        	ans = max(ans,max(dp1[i],dp2[i]));
        }

    	return ans;
    }
};