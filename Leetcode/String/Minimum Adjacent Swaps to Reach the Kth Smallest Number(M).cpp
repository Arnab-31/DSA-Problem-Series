//https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/


//Approach - Find kth permuation, then find no of swaps needed to get that permutation. 

class Solution {
public:
    
    void permutation(string &arr){    // this can done using stl function - next_permutation(begin(arr), end(arr));
        int n = arr.size();
        int i;
        for(i = n-2;i>=0;i--){
            if(arr[i] < arr[i+1])
                break;
        }
        //it is guaranteed that a valid next permutation exists
        int j;
        for(j=n-1;j>i;j--){
            if(arr[j]>arr[i]) 
                break;
        }
        swap(arr[i] , arr[j]);
        reverse(arr.begin() + i + 1 , arr.end());   
    }
    
    int getMinSwaps(string num, int k) {
        string val = num;
        while(k--)
            permutation(val);
        int ans = 0 , n = num.length();
		//now compare num and val to find minimum number of adjancent swappings
		//for each num[i] move it to its corresponding position in 'val' by swapping adjacent elements.
		//Count each such swap
        for(int i=0;i<n;i++){
            if(num[i] != val[i]) {
                int j = i+1;
                while(num[j] != val[i]) 
                    j++;
                while(i<j) {
                    swap(num[j] , num[j-1]);
                    j--;
                    ans++;
                }
            }
        }        
        return ans;
    }
};