https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1


Approach - refer notes
TC - nlog(n)


class Solution
{
    public:
    //Function to insert heap.
    priority_queue <int> q1;
    priority_queue <int, vector<int>, greater<int> >q2;
    
    void insertHeap(int &x)
    {
        if(q1.empty() || q1.top() > x)
            q1.push(x);
        else
            q2.push(x);
            
        
        if(q1.size() > q2.size() + 1)
        {
            q2.push(q1.top());
            q1.pop();
        }
        else if(q2.size() > q1.size() + 1)
        {
            q1.push(q2.top());
            q2.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(q1.size() == q2.size())
            return (q1.top() + q2.top()) / 2.0;
        else if(q1.size() > q2.size())
            return q1.top();
        else
             return q2.top();
    }
};
