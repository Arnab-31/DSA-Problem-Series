//https://leetcode.com/problems/maximum-value-of-k-coins-from-piles

// The main idea here is to use Dynamic programming and I have used prefix sum to get the total sum of the top elements uptil the index where I am standing at any instance.

// Dp states are : (index , k)

// index defines the stack which we are currently on
// k defines the number of elements which we can remove from the top of the stacks
// We have 2 choice sstanding at any index : either take the elements
// or skip the current stack and find for optimal answers in other indexes;

// If we take the elements from the stack we have options to take as much elements from the current stack as we want( limitations : until k gets finished or the stack gets finished ) by running a loop we can iterate over all the possibilities and get the optimal option from it.





class Solution {
    
    int help(int ind , int k, vector<vector<int>>&a, vector<vector<int>>&dp){
		//base cases
		if(k == 0)  return 0;
        if(k < 0)   return INT_MIN;
        if(ind < 0)    return 0;
		
		//memoization step
        int &ans = dp[ind][k];
        if(ans != -1)   return ans;     
		//you can either skip the current stack or take from it
		
        ans = help(ind-1, k , a, dp);  // option 1. skip the current stack
        int current_pile_size = a[ind].size();
		// this is the limit of elements you can take from the current stack
        int limit = min(k, current_pile_size-1);  
        
        for(int i=0;i<=limit;i++){ //this loop will give me how many items i can take from the stack
            int take = a[ind][i] ;   // since prefix sum is done we get the total elements uptil this index using a[ind][i]
            ans = max(ans, take + help(ind-1, k-i-1, a, dp));  // we take the max of all the available options
        }
        return ans;
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int size = piles.size(); 
        for(auto &it: piles){
            int n = it.size();
            for(int i=1;i<n;i++)
                it[i] += it[i-1];  // prefix sum ...so we can get cumulative sum upto a point
        }
        vector<vector<int>>dp(size+1, vector<int>(k+1, -1));
        return help(size-1, k, piles, dp);
    }
};