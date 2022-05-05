//https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1#

class Solution{
    public:
    /*You are required to complete below method */
    long long int  countPS(string s)
    {
       //Your code here
       long long int mod  = 1000000007;
       long long int dp[s.length()][s.length()];
       
      
       for(long long int len=1;len<=s.length();len++){
           for(long long int i=0;i<=s.length()-len;i++){
               long long int j = i + len - 1 ;
               
                if(i == j)
                    dp[i][j] = 1;
                else if(len == 2){
                    if(s[i] == s[j])
                        dp[i][j] = 3;
                    else
                        dp[i][j] = 2;
                }
                else{
                    if(s[i] == s[j])
                        dp[i][j] = (1 + dp[i+1][j] + dp[i][j-1])%mod;
                    else{
                        dp[i][j] = (((dp[i+1][j] + dp[i][j-1])%mod - dp[i+1][j-1])%mod + mod)%mod;
                    }
                }
                
             
           }
           
       }
       
       return dp[0][s.length()-1];
    }
     
};