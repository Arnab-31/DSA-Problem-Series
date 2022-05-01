//https://leetcode.com/problems/k-divisible-elements-subarrays/

//Appoach - Keep finding all subarrays using bruteforce, if no of elements divisble by p is less than k+1, push it into set to elimintate duplicates.
//NOTE - Sometimes bruteforce is the way to go. DOnt overthink.


class Solution {
public:

    int countDistinct(vector<int>& nums, int k, int p) {
        
        int n=nums.size();
        set<vector<int>>ans;
        
        int i,j;
        for(i=0;i<n;i++)
        {
            vector<int>tt;
            int ct=0;
            for(j=i;j<n;j++)
            {
                tt.push_back(nums[j]);
                if(nums[j]%p==0)
                    ++ct;
                if(ct>k)
                    break;
                ans.insert(tt);
                    
            }
        }
        return ans.size();
    }
    
};