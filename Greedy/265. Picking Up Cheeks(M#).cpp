Question: https://www.spoj.com/problems/GCJ101BB/


Solution: 

TC: O(n)

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin>>t;
    int m = 1;
    while(m<=t){
        ll n,k,b,t;

        cin>>n>>k>>b>>t;

        ll X[n],V[n];
        for(int i=0;i<n;i++)
            cin>>X[i];
        for(int i=0;i<n;i++)
            cin>>V[i];

        long double T[n];
        for(int i=0;i<n;i++)
            T[i] = ((double)(b-X[i]) )/V[i];

        ll totalpicks = 0;
        ll picks=0;
        ll j=0;
        vector <int> v;
        for(int i=n-1;i>=0;i--)
        {
            if(T[i]<=t)
            {
                totalpicks = totalpicks + picks;
                j++;
                if(j==k)
                    break;
            }
            else
                picks++;
        }

        if(j<k)
            cout<<"Case #"<<m<<": IMPOSSIBLE"<<endl;
        else{
            cout<<"Case #"<<m<<": "<<totalpicks<<endl;
        }
        m++;
    }

    return 0;
}