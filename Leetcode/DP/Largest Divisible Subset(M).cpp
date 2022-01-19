//https://leetcode.com/problems/largest-divisible-subset/

//Similar to LIS
//1. Sort all array elements in increasing order. The purpose of sorting is to make sure that all divisors of an element appear before it.
//2. Create an array dp[] of same size as input array. dp[i] stores size of divisible subset ending with arr[i] (In sorted array). The minimum value of dp[i] would be 1.
//3. Traverse all array elements. For every element, find a divisor arr[j] with largest value of dp[j] and store the value of dp[i] as dp[j] + 1.



class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
   
        int dp[nums.size()];
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
            dp[i] = 1;
        
        int ans = 1;
        int idx = 0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = 1 + dp[j];
                        
                        if(dp[i] > ans){
                            ans = dp[i];
                            idx = i;
                        }
                            
                    }
                }
            }
        }
        
    
        
        vector<int>v;
        v.push_back(nums[idx]);
        ans--;
        int prev = idx;
        for(int i=idx-1;i>=0;i--){
            if(nums[prev] % nums[i]== 0 && dp[i] == ans){
                v.push_back(nums[i]);
                prev = i;
                ans--;
            }
        }
        
        reverse(v.begin(), v.end());
        return v;
    }
};