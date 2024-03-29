Question: https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations/0#

Solution: 
TC: O(nlogn)

#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin>>t;
    while(t--)
    {
      long long int n; cin>>n; long long int a[n],s=0;
      for(int i=0;i<n;i++) cin>>a[i];
      sort(a,a+n);
      for(int i=0;i<n;i++) {s+=(i*a[i])%1000000007;}
      cout<<s%1000000007<<endl;
    }
	return 0;
}