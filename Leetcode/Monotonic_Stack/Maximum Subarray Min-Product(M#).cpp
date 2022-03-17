//https://leetcode.com/problems/maximum-subarray-min-product/

//Approach - for every number in nums just search for the smallest element in its left and in right.
//than just using prefix sum and suffix sum calculate your value for your answer

#define ll long long 
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        
        ll prefix[100000+1]{0};
        ll suffix[100000+1]{0};        
        ll n = nums.size();
        unordered_map<ll,ll> minL,minR;        
        stack<ll>st,st2; //to store indices, no need of stack of pairs 
		long long sum = 0 , ans = 0;
		//prefix sum
        for(ll i=0;i<n;++i){
            prefix[i] = nums[i];
            if(i-1 >= 0)prefix[i] += prefix[i-1];
        }
		//suffix sum
        for(ll i=n-1;i>=0;--i){
            suffix[i] = nums[i];
            if(i+1 < n)suffix[i] += suffix[i+1];
        }
		//find left minimum index for each of the present index 
        for(int i=n-1;i>=0;--i){
            while(!st.empty() and nums[st.top()] >= nums[i])
                st.pop();
            if(!st.empty() and nums[st.top()] < nums[i])
                minR[i] = st.top();
            st.push(i);
        }
	//find right minimum index for each of the present index 
        for(int i=0;i<n;++i){
            while(!st2.empty() and nums[st2.top()] >= nums[i])
                st2.pop();
            if(!st2.empty() and nums[st2.top()] < nums[i])
                minL[i] = st2.top();
            st2.push(i);
        }      
  	//find the answer by considering each element as the smallest element and
  	//including the maximum length array from left and right 
  	
  	
      for(int i=0;i<n;++i){                        
          long long val = prefix[i] + suffix[i] - nums[i];            
          if(minL.count(i))
              val -= prefix[minL[i]];
          if(minR.count(i))
              val -= suffix[minR[i]];                          
          val *= nums[i];                        
          ans = max(ans,val);            
      }
    int mod = 1e9+7;
    return ans%mod;
}
};