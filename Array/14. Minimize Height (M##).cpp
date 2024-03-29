https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

Approach - refer notes
TC - O(nlogn)
SC - O(n)



int getMinDiff(int arr[], int n, int k) {
        // code here
     
        sort(arr, arr + n);
        
        int ans=arr[n-1] - arr[0];
        for(int i=0;i<n-1;i++)
        {
            int ma = max (arr[i] + k , arr[n-1] - k);             //max height by adding all heights with k til i
            int mi = min ( arr[0] + k, arr[i+1] - k );            //min height by subtracting k from all heights after i
            
            if( mi >=0 )                                         //negative height not allowed so proceed ton next iteration
                ans = min(ans , ma - mi);
        }
        
        return ans;
    }