https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1


class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int s=0;
        for(int i=0;i<N;i++)
            s=s+arr[i];
            
        if(s%2!=0)
            return 0;
        
        s=s/2;
        
        bool dp[N+1][s+1];
        
        for(int i=1;i<s+1;i++)
            dp[0][i] = false;
            
        for(int i=0;i<N+1;i++)
            dp[i][0] = true;
        
        
        for(int i=1;i<N+1;i++)
        {
            for(int j=1;j<s+1;j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = (dp[i-1][j]) || (dp[i-1][j - arr[i-1]]);
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        if(dp[N][s])
            return 1;
        else
            return 0;
        
    }
};