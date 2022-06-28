//https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/submissions/

//Sort it, and then start removing the end elements because we would only want to change a element to a number within the smallest amplitude. There are 4 options, remove all 3 from the end, remove 2 from end 1 from start, remove 1 from end and 2 from start, remove 3 from start.

class Solution {
public:
    int solve(vector<int>nums, int i, int j,  int k){
        if(k == 0) return nums[j] - nums[i];
        
        return min(solve(nums, i+1, j,k-1), solve(nums, i, j-1, k-1));
    }
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;
        
        sort(nums.begin(), nums.end());
        
        int dif = INT_MAX;
        int i=0,j=nums.size()-1;
        int ans = solve(nums, i, j, 3);
       
        return ans;
    }
};