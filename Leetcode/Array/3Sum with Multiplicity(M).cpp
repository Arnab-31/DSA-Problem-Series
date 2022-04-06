//https://leetcode.com/problems/3sum-with-multiplicity/

//Approach - Sort , then for every element do two pointers to find the other two elements. Edge Case -  The other two element can be same.


class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        long long mod=1e9+7;
        int res = 0;
        for(int i=0;i<arr.size()-2;i++){
            int l = i+1;
            int r = arr.size()-1;
            
            while(l < r){
                if(arr[i] + arr[l] + arr[r] == target){
                    int lcount = 1, rcount = 1;
                    int lval = arr[l], rval = arr[r];
                    while(l < r && arr[l+1] == arr[l]){
                        l++;
                        lcount++;
                    }
                    
                    
                    while(l < r && arr[r] == arr[r-1]){
                        r--;
                        rcount++;
                    }
                    
                    if(l == r){ //Both element same, so we use nC2 for calculations
                        res =  (res%mod + (lcount%mod * (lcount-1)%mod)/2)%mod;
                    }
                    
                    if(l!= r){ 
                        res = (res%mod +  (lcount%mod * rcount%mod)%mod)%mod;
                    }
                    
                    l++;
                    r--;
                    
                }else if(arr[i] + arr[l] + arr[r] > target)
                    r--;
                else
                    l++;
            }
        }
        
        return res;
    }
};