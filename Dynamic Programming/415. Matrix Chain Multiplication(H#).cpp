Question: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
Youtube: https://www.youtube.com/watch?v=kMK148J9qEE&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=34


#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
int MatrixChainOrder(int arr[], int i, int j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];

    if(i>=j)
        return 0;

    int min=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int tempAns = MatrixChainOrder(arr,i,k) + MatrixChainOrder(arr,k+1,j) +
                    (arr[i-1] * arr[k] * arr[j]);

        if(tempAns < min)
            min=tempAns;
    }

    return dp[i][j]=min;

}
int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    memset(dp, -1, sizeof(dp));

    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, 1, n - 1);
}
