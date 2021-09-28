Question: https://www.spoj.com/problems/GERGOVIA/

Solution: 
TC: slightly more than O(n)

#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
    while(true){
        ll n;
        cin>>n;
        if(n==0)
            break;

        ll house[n];
        for(ll i=0;i<n;i++)
            cin>>house[i];

        queue <pair<int,int>> q;   //keep track of the past demands using a pair queue
        ll work = 0;
        for(ll i=0;i<n;i++)
        {
            ll demand = house[i];
            if(q.empty())
                q.push(make_pair(i,demand));
            else if(demand > 0)
            {
                if(q.front().second > 0)
                    q.push(make_pair(i,demand));
                else
                {
                    while (!q.empty())
                    {
                        ll cd = q.front().second;
                        if((demand + cd) == 0)
                        {
                            work = work + (i - q.front().first) * demand;
                            demand = 0;
                            q.pop();
                            break;
                        }
                        else if((demand + cd) < 0)
                        {
                            work = work + (i - q.front().first) * demand;
                            q.front().second = demand + cd;
                            demand = 0;
                            break;
                        }
                        else
                        {
                            work = work + (i - q.front().first) * abs(q.front().second);
                            demand = demand + cd;
                            q.pop();
                        }
                    }

                    if(demand!=0)
                        q.push(make_pair(i,demand));
                }
            }
            else
            {
                if(q.front().second < 0)
                    q.push(make_pair(i,demand));
                else
                {
                    while (!q.empty())
                    {
                        ll cd = q.front().second;
                        if((demand + cd) == 0)
                        {
                            work = work + (i - q.front().first) * abs(demand);
                            demand = 0;
                            q.pop();
                            break;
                        }
                        else if((demand + cd) > 0)
                        {
                            work = work + (i - q.front().first) * abs(demand);
                            q.front().second = demand + cd;
                            demand = 0;
                            break;
                        }
                        else
                        {
                            work = work + (i - q.front().first) * q.front().second;
                            demand = demand + cd;
                            q.pop();
                        }
                    }

                    if(demand!=0)
                        q.push(make_pair(i,demand));
                }
            }

        }
        cout<<work<<endl;
    }
}