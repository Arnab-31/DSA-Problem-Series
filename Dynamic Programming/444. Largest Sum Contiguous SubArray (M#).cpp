https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1


Use Kadane's Algo (DP not required)

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int curSum=0;
        int maxSum=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            curSum = curSum + arr[i];
            
            maxSum = max(maxSum, curSum);
            
            if(curSum < 0)
                curSum=0;
        }
        
        return maxSum;
    }
};