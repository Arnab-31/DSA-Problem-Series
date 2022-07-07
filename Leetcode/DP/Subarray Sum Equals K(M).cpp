//https://leetcode.com/problems/subarray-sum-equals-k/

//Approach - https://leetcode.com/problems/subarray-sum-equals-k/discuss/1759909/C%2B%2Bor-Full-explained-every-step-w-Dry-run-or-O(n2)-greater-O(n)-or-Two-approaches

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int s  = 0 ;
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            s += nums[i];
            ans += mp[s-k];
            mp[s]++;
            if(s == k) ans++;
        }
        
        return ans;
    }
};