//https://leetcode.com/problems/132-pattern

//Approach - We use a kind of monotonic stack. When we have a new element , we check if the elements present in the stack can 
//act as the middle element, the current element as the right most element and the min element till the middle element as the left most element.
//In Line 17, we keep popping the stack element, if they are less than the current element , as they can not be the middle element as for that it needs to be greatest of the three element.
//In Line 21, if check if there is still some element left in stack, which means it is a potential middle element, then we compare the current element with the left most element. If conditions satisfy, we return true.
//If thats not true,  we keep the stack element and also push the current element, as they can be present in 132 pattern with future numbers. 

//So we basically maitaining a decreasing ordered stack paired up with the min element. For Any new element , we check it with a larger element that we recently saw, and see it a 13 pattern is possible. 

//TC - O(n)

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
       
        stack<pair<int, int>>st;
        int mi = nums[0];
        for(int i=1;i<nums.size();i++){
            
            while(!st.empty() && st.top().first <= nums[i])
                st.pop();
            
            if(!st.empty() && st.top().second  < nums[i])
                return true;
            
            st.push({nums[i] , mi});
            mi = min(mi, nums[i]);
        }
        return false;
    }
};