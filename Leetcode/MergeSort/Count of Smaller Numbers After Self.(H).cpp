//https://leetcode.com/problems/count-of-smaller-numbers-after-self/


//Approach - The comparisons needed in the question are noramally perfromed in merge sort. So we can do it in O(nlogn) time.

class Solution {
public:
    
    vector<int> mergeSort(vector<pair<int,int>>v, vector<int>&ans, int l, int h){
             
        if(l == h){
            vector<int>res;
            res.push_back(nums[l]);
            return res;
        }
        
        vector<pair<int,int>>lf = mergeSort(v, ans, l, h/2);
        vector<pair<int,int>>rf = mergeSort(v, ans, h/2+1, h);
        vector<pair<int,int>>res = merge(lf, rf, ans);
        return res;
    }
    
    vector<int> merge(vector<pair<int,int>>l, vector<pair<int,int>>r, vector<int>&ans){
        
        int i = 0,j=0;
        vector<pair<int,int>>res;
        
        while(i < l.size() && j < r.size()){
            if(l[i].first > r[j].first){
                ans[l[i]].second]++;
                res.push_back(r[j]);
                j++;
            }else{
                res.push_back(l[i]);
                i++;
            }   
        } 
        while(j < r.size()){
              res.push_back(r[j]);
              j++;
        }  
        
        bool flag  =  false;
        while(i < l.size()){
              if(!flag){
                  ans[l[i].second]+= 
              }
              res.push_back(r[j]);
              j++;
        }
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        
        vector<int>ans(nums.size());
        if(nums.size() == 1){
            ans.push_back(0);
            return ans;  
        }
        
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i], i});
        }
        
        mergeSort(nums, ans, 0, nums.size()-1);
        return ans;
    }
};