https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1#


Approach - 
Sort the given array.
Loop over the array and fix the first element of the possible triplet, arr[i].
Then fix two pointers, one at i + 1 and the other at n – 1. And look at the sum, 
If the sum is smaller than the required number, increment the first pointer.
Else, If the sum is bigger, decrease the end pointer to reduce the sum.
Else, if the sum of elements at two-pointer is equal to given number return true.

Tc - O(N^2)
SC - O(1)


class Solution {
    public:
bool find3Numbers(int A[], int n, int X)
{
    //Your Code Here
    sort(A,A+n);
    
    for(int i = 0; i< n-2;i++)
    {  
      
        int a=i+1;
        int b=n-1;
        
        while(a < b)
        {
        
            if(A[i] + A[a] + A[b] == X)
                return true;
            else if(A[i] + A[a] + A[b] < X)
                a++;
            else
                b--;
        }
    }
    
    return false;
}
};