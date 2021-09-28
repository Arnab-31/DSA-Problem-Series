Question: https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

[ In this question whenver u cut a segment into two, the length of both the parts should be among x,y,z. So suppose u cut a length sengment of 5 by 4.
Then resulting lenghts are 1 and 4. Both these should be present in x,y,z then only this cutting is possible]


//Complete this function
int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    int dp[n+1];
    
    if(n < min({x,y,z}))
        return 0;

    
    dp[0]=0;
    
  
    for(int i=1;i<=n;i++)
    {
       
        dp[i] = -1;               //Lets assume cutting is not possible at this length 
     
        
        if(i-x >= 0)
        {
            dp[i] = max(dp[i],dp[i-x]);
           
        }
        if(i-y >= 0)
        {
              dp[i] = max(dp[i],dp[i-y]);
            
        }
        if(i-z >= 0)
        {
             dp[i] = max(dp[i],dp[i-z]);
           
        }
        
        if(dp[i] != -1)        // If cutting is possible then we include the current cut and increase the value by one
            dp[i]++;
    }
    
    return max(dp[n], 0);    //In case value is -1, which measns not possible to cut , we print 0
}