https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1


Tc - O(r*c)
Sc - O(r*c)


class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here
    vector<int>ans;
    int minr = 0,minc=0,maxr=r-1,maxc=c-1;
    
    int count=0;
    
    while(count < r*c)
    {
        
        for(int i=minc;i<=maxc;i++)
        {
            if(count < r*c)
            {
                ans.push_back(matrix[minr][i]);
                count=count+1;
            }
        }
        minr = minr + 1;
        
        for(int i=minr;i<=maxr;i++)
        {
            if(count < r*c)
            {
                ans.push_back(matrix[i][maxc]);
                count=count+1;
            }
        }
        maxc = maxc - 1;
        
        for(int i=maxc;i>=minc;i--)
        {
            if(count < r*c)
            {
                ans.push_back(matrix[maxr][i]);
                count=count+1;
            }   
        }
        maxr = maxr - 1;
        
        for(int i=maxr;i>=minr;i--)
        {
            if(count < r*c)
            {
              ans.push_back(matrix[i][minc]);
              count=count+1;
            }
        }
        minc = minc  + 1;
    }
    
    return ans;
    }
};