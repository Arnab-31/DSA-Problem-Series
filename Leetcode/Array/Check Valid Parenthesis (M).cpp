//https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/


//Check for orphan ")" from left to right anf check for "(" from right to left

class Solution {
public:
    //Time Complexity O(n)
    //Space Complexity O(1)
    bool canBeValid(string s, string locked) {
        int n=s.size();
        if(n&1) return 0;
        int lockedOpen=0,lockedClose=0,free=0;

        for(int i=0;i<n;i++){ //left to right
            if(locked[i]=='0') free++;
            else{
                if(s[i]=='(') lockedOpen++;
                else lockedClose++;
            }
            if(lockedClose>free+lockedOpen) return 0;
        }

        lockedOpen=0,lockedClose=0,free=0;
        for(int i=n-1;i>=0;i--){ //right to left
            if(locked[i]=='0') free++;
            else{
                if(s[i]=='(') lockedOpen++;
                else lockedClose++;
            }

            if(lockedOpen>free+lockedClose) return 0;
        }
        return 1;
    }
};