//https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

//Approach - Create two array even and odd, and which stores the no of even prefix suns and odd prefix sums present till ith element
//If prefixSum[i] is even, then we need to subtract odd prefix sum from it to make the sum odd, so we use the odd array to find out how many odd prefix sums occoured till now.
//If prefixSum[i] is odd, then we take the current subarray and also we  need to subtract even prefix sum from it to get other arrays which keeps the sum odd, so we use the even array.



class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
       
        int odd[arr.size()];
        int even[arr.size()];
        
        int sum = 0;
        
        int ec = 0, oc = 0;
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            
            if(sum % 2 ==0)
                ec++;
            else
                oc++;
            
            odd[i] = oc;
            even[i] = ec;
               
            if(sum % 2 != 0)
                ans += (even[i]%1000000007 + 1)%1000000007;
            else
                ans += odd[i]%1000000007;
            
            ans %= 1000000007;
        }
        
        return ans;
    }
};