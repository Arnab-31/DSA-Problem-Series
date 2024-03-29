Question: https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1#


class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // code here
        int dp[n][m];
        int max=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    dp[i][j]=0;        //If value is 0 means no square matrix can be formed at that point
                    continue;
                }
                
                dp[i][j]=1;            //If value is 0 means at least one square matrix of size 1 can be formed at that point
                
                if(i!=0 && j!=0)
                    dp[i][j] = min({dp[i-1][j-1],dp[i-1][j], dp[i][j-1]}) +1;    
                
                if(dp[i][j]>=max)
                    max=dp[i][j];
            }
        }
        
        return max;
    }
    
};