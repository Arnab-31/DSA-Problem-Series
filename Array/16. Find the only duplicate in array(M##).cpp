https://leetcode.com/problems/find-the-duplicate-number/solution/


Solution  - 1

Approach - Sorting
TC - O(nlogn)
SC - O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int ans;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                ans = nums[i];
                break;
            }
        }
            
        return ans;
    }
};



Solution  - 2

Approach - Form a linkedlist using the value,  a cycle will be formed due to the duplicate and now using Floyd's algorithm , find the origin of the cycle
TC - O(nlogn)
SC - O(1)


class Solution {
  public int findDuplicate(int[] nums) {
    // Find the intersection point of the two runners.
    int tortoise = nums[0];
    int hare = nums[0];
    do {
      tortoise = nums[tortoise];
      hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Find the "entrance" to the cycle.
    tortoise = nums[0];
    while (tortoise != hare) {
      tortoise = nums[tortoise];
      hare = nums[hare];
    }

    return hare;
  }
}

