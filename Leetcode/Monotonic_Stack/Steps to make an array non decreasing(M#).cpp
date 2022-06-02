//https://leetcode.com/problems/steps-to-make-array-non-decreasing/


//Appriach - We have to use mono tonic stack. But we need to traverse the array in the reverse order. Always check from which side we should traverse the array.
//In this case traversing from reverse order makes the question easiy solvable.
//Explanatation - https://www.youtube.com/watch?v=NQGduRE1Crk&ab_channel=CodingDecoded
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>>st;
        
        int res = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(st.empty()){
                st.push({nums[i], -1});
                count = 0;
            }
            else{  
                if(st.top().first > nums[i]){
                    
                    if(nums[i] >= st.top().second){
                        count++;
                    }else
                        count = 0;
                    st.top().second = nums[i];
                }else{
                    st.push({nums[i], -1});
                    count = 0;
                }
                res = max(res, count);
            }
        }
        
        return res;
    }
    
    
};