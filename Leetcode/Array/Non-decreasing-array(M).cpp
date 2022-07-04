//https://leetcode.com/problems/non-decreasing-array/discuss/2193223/C%2B%2B-oror-EXPLAINED-oror-BEATS-100-oror-OPTIMIZED-oror-TC-greater-O(n)

//Approach - https://www.youtube.com/watch?v=sgCFEv28aBk


class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int violation = 0;
        for(int i=1;i<nums.size();i++){
            // case for violation
            if(nums[i-1] > nums[i]){
                
                // at max, we can have one violation. So if it has been occured before => return false
                if(violation == 1){
                    return false;
                }
                //if no prev violation, then violation++
                violation++;
               
                // fixing violation => operation 1
                if(i<2 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                // fixing violation => operation 2
                else
                    nums[i] = nums[i-1];
                
            }
        }
        // if traversal of vector was successfull and return statement was not invoked then return true.
        return true;
    }
};
