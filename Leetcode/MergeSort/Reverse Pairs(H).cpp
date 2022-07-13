//https://leetcode.com/problems/reverse-pairs/


//Approach - Using merge sort to use the arr[i] < arr[j] property and the sorted left and right half helps us in do the couting
//https://www.youtube.com/watch?v=DCbPOZTNfHc&t=5506s&ab_channel=CodeBeyond


//TC - nlogn
class Solution {
public:
    int ans = 0;
   
    void merge(vector<int>&arr, int a, int b , int c, int d){
        
        int ub = a;
        for(int i=c;i<=d;i++){
//             //this is using binary search which will take log n for every right element
//             int low = a;
//             int high = b;
//             int lowerbound = -1;
//             while(low <= high){
//                 int mid = (high+low)/2;
//                 if(arr[mid] > ((long long int)arr[i]*2)){
//                     lowerbound = mid;
//                     high = mid-1;
//                 }else
//                     low = mid+1; 
//             }
            
//             if(lowerbound != -1){
//                 ans += b - lowerbound + 1;
//             }
//             cout<<ans<<" "<<b - lowerbound + 1<<" "<<lowerbound<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
            
           //this will take o(n) total for the entire right part
            while(ub <= b && arr[ub] <= (long long)arr[i]*2){
                ub++;
            }
            ans += b-ub+1;
        }
        
        vector<long long int>temp;
        long long int i = a,j=c;
        while(i<=b && j<=d){
            if(arr[i] <= arr[j])
                temp.push_back(arr[i++]);
            else{
                temp.push_back(arr[j++]);
            }
        }
        
        while(i<=b) temp.push_back(arr[i++]);
        while(j<=d) temp.push_back(arr[j++]);
        
        
        i = a;
        for(auto s : temp){
              arr[i++] = s;  
        }
    }
    
    
    void mergeSort(vector<int>&nums, int a, int b){
        if(a == b) return;
        
        int mid = a + (b-a)/2;
        mergeSort(nums, a, mid); 
        mergeSort(nums, mid+1, b);   //logn for this and above
        merge(nums, a, mid, mid+1, b); //2n
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        ans = 0;
        mergeSort(nums, 0, n-1);
        
        return ans;
    }
};