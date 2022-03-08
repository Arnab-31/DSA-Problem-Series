//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v = nums;
        sort(v.begin(), v.end());
        
        int a = -1;
        bool flag = false;
        for(int i=0;i<v.size();i++){
            a++;
            if(v[i]!=nums[i]){
                flag = true;
                break;
            }       
        }
        
        if(!flag)
            return 0;
        
        int b = nums.size();
        flag = false;
        for(int i=v.size()-1;i>=0;i--){
            b--;
            if(v[i]!=nums[i]){
                flag = true;
                break;
            }       
        }
        
        return b-a+1;
        
        
        
    }
};