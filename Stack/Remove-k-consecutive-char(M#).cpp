//https://www.geeksforgeeks.org/reduce-the-string-by-removing-k-consecutive-identical-characters/


// CPP program for the above approach
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Basic Approach is to create a Stack that store the
// Character and its continuous repetition number This is
// done using pair<char,int> Further we check at each
// iteration, whether the character matches the top of stack
// if it does then check for number of repetitions
// else add to top of stack with count 1

class Solution {
public:
	string remove_k_char(int k, string s)
	{

		// Base Case
		// If k=1 then all characters
		// can be removed at each
		// instance
		if (k == 1)
			return "";
		// initialize string
		string output = "";

		// create a stack using pair<> for storing each
		// character and corresponding
		// repetition
		stack<pair<char, int> > stk;

		// iterate through the string
		for (int i = 0; i < s.length(); i++) {

			// if stack is empty then simply add the
			// character with count 1 else check if
			// character is same as top of stack
			if (stk.empty() == true) {
				stk.push(make_pair(s[i], 1));
			}
			else {

				// if character at top of stack is same as
				// current character increase the number of
				// repetitions in the top of stack by 1
				if (s[i] == (stk.top()).first) {
					stk.push(
						{ s[i], stk.top().second + 1 });
					if (stk.top().second == k) {
						int x = k;
						while (x) {
							stk.pop();
							x--;
						}
					}
				}
				else {

					// if character at top of stack is not
					// same as current character push the
					// character along with count 1 into the
					// top of stack
					stk.push(make_pair(s[i], 1));
				}
			}
		}

		// Iterate through the stack
		// Use string(int,char) in order to replicate the
		// character multiple times and convert into string
		// then add in front of output string
		while (!stk.empty()) {
			output += stk.top().first;
			stk.pop();
		}
		reverse(output.begin(), output.end());
		return output;
	}
};

// Driver Code
int main()
{

	string s = "geeksforgeeks";
	int k = 2;
	Solution obj;
	cout << obj.remove_k_char(k, s) << "\n";

	return 0;
}

// This code has been contributed by Navansh Goel
