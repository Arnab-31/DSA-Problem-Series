//https://leetcode.com/problems/two-best-non-overlapping-events/

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& e) {
        int size=e.size(),ans=0,maxi=0;
        sort(e.begin(),e.end());  //sorting the intervals based on start time
        map<int,int>mp;
        while(size--){  //traversing the intervals from the end
            auto it=mp.upper_bound(e[size][1]);  // first interval in the sorted array which starts after the end of the current interval 
            maxi=max(maxi,e[size][2]); // max value till this interval from end
              mp[e[size][0]]=maxi;
            if(it==mp.end())  
                ans=max(ans,maxi);  
            else
                ans=max(ans,e[size][2]+it->second);
        }
        return ans;
    }
};
