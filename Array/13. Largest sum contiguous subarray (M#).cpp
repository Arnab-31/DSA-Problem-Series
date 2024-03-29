https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1


Appraoch - Kadane's algo
TC - O(n)
SC - O(1)

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int max = INT_MIN;
        int s = 0;
        
        for(int i=0;i<n;i++)
        {
            s = s + arr[i];
            
            if(s  > max)
                max = s;
                
            if(s < 0 )
                s = 0;
        }
        
        
        return max;
    }
};
