https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

Approach - Everytime add the smallest two rope length
TC - O(nlogn)


class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
         priority_queue <long long, vector<long long>, greater<long long> >h;
         
         for(int i=0;i<n;i++)
            h.push(arr[i]);
        
        long long cost = 0;
        while(h.size()!=1)
        {
            long long a = h.top();
            h.pop();
            long long b= h.top();
            h.pop();
            cost = cost + a + b;
            h.push(a+b);
        }
        
        return cost;
    }
};