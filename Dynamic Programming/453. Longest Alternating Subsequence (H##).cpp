https://www.geeksforgeeks.org/longest-alternating-subsequence/


// C++ program to find longest alternating
// subsequence in an array
#include<iostream>
using namespace std;

// Function to return max of two numbers
int max(int a, int b)
{
	return (a > b) ? a : b;
}

// Function to return longest alternating
// subsequence length
int zzis(int arr[], int n)
{
	
	/*las[i][0] = Length of the longest
		alternating subsequence ending at
		index i and last element is greater
		than its previous element
	las[i][1] = Length of the longest
		alternating subsequence ending
		at index i and last element is
		smaller than its previous element */
	int las[n][2];

	// Initialize all values from 1
	for(int i = 0; i < n; i++)
		las[i][0] = las[i][1] = 1;
	
	// Initialize result
	int res = 1;

	// Compute values in bottom up manner
	for(int i = 1; i < n; i++)
	{
		
		// Consider all elements as
		// previous of arr[i]
		for(int j = 0; j < i; j++)
		{
			
			// If arr[i] is greater, then
			// check with las[j][1]
			if (arr[j] < arr[i] &&
				las[i][0] < las[j][1] + 1)
				las[i][0] = las[j][1] + 1;

			// If arr[i] is smaller, then
			// check with las[j][0]
			if(arr[j] > arr[i] &&
			las[i][1] < las[j][0] + 1)
				las[i][1] = las[j][0] + 1;
		}

		// Pick maximum of both values at index i
		if (res < max(las[i][0], las[i][1]))
			res = max(las[i][0], las[i][1]);
	}
	return res;
}

// Driver code
int main()
{
	int arr[] = { 10, 22, 9, 33,
				49, 50, 31, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	cout << "Length of Longest alternating "
		<< "subsequence is " << zzis(arr, n);
		
	return 0;
}

// This code is contributed by shivanisinghss2110



//Code written by me

class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		    int n = nums.size();
		    int dp[n][2];
		    dp[0][0] = 1;
		    dp[0][1] = 1;
		    
		    int ans = 1;
		    for(int i=1;i<=n-1;i++){
		        dp[i][1] = dp[i-1][1];
		        dp[i][0] = dp[i-1][0];
		        if(nums[i] < nums[i-1]){
		            dp[i][0] = 1 + dp[i-1][1];
		            dp[i][1] = dp[i-1][1];
		        }else if(nums[i] > nums[i-1]){
		            dp[i][1] = 1 + dp[i-1][0];
		            dp[i][0] = dp[i-1][0];
		        }
		        //cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
		        ans = max({ans, dp[i][1], dp[i][0]});
		    }
		    
		    return ans;
		}

};
