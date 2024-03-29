Question: https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1#


  class Solution
{
    public:
    long long countWays(int n, int k)
    {
        long long dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[1] = k;
        long long same = 0, diff = k;   
        // same means we are making the current element same color as the last one
        // diff means we are making the current element differert color as the last one
        
        for (int i = 2; i <= n; i++)
        {
            same = diff;     //if we have to make current element same as the last one then we have only option so same==diff
            diff = dp[i-1] * (k-1);  //here we have k-1 color oprions as we are making it diffeent colot
            diff%=1000000007;
            dp[i] = (same + diff);   // total is sum of sum and dif
            dp[i]%=1000000007;
        }
     
        return dp[n];
    }
};