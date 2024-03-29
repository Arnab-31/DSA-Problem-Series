https://leetcode.com/problems/next-permutation/solution/


Approach - refer notes
TC - O(N)
SC - O(1)


public class Solution {
    public void nextPermutation(int[] nums) {
        int i = nums.length - 2;
        
        //find the first decreasing element from right
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        
        //find the first element from the right which is greater than the found element and swap them
        if (i >= 0) {
            int j = nums.length - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i + 1);
    }

    private void reverse(int[] nums, int start) {
        int i = start, j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}