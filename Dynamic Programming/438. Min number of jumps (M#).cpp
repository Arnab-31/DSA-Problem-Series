Question: https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#


1) O(N^2) DP solution


class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        
        int dp[n];
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            dp[i]=INT_MAX;
            for(int j=0;j<i;j++){
                
                if(arr[j]>=(i-j) && dp[j]<=dp[i])
                {
                    dp[i]=dp[j];
                }
            }
            if(dp[i]!=INT_MAX)
                dp[i]++;
        }
        
        if(dp[n-1] == INT_MAX)
            return -1;
        
        return dp[n-1];
    }
};


2) O(N) non dp solution

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(arr[0]==0)
            return -1;
        
        int maxR=arr[0];      //current max range without any jump
        int step=arr[0];      //no of steps left
        int jump = 1;         //no of jumps taken
        
        for(int i=1;i<n-1;i++) //if we have step left till n-2 index means we were able to reach end
        
            step--;          //we moved forward so reduce number of steps
            if(i+arr[i]>maxR)  //increase max range if we can based on current value
                maxR=arr[i]+i; 
                
            if(step==0)       //if no more steps left, means we we have to jump now
            {
                jump++;
                if(maxR <= i)  //if max range is same as current index, and we dont have any step left, means we can not go any further
                    return -1;
                step = (maxR - i);  //now we can again go till the new max range,so update the steps
            }
        }

        return jump;
    }
};