// CPP program to count the
// number of numbers in range
// 1-M that are divisible by
// given N prime numbers
#include <bits/stdc++.h>
using namespace std;

// function to count the number
// of numbers in range 1-M that
// are divisible by given N
// prime numbers
int count(int a[], int m, int n)
{
	int odd = 0, even = 0;
	int counter, i, j, p = 1;
	int pow_set_size = (1 << n);

    //Finding all combination using power set method.
	// Run from counter 000..0 to 111..1
	for (counter = 1; counter < pow_set_size; counter++) { //counter goes from 1 to 2^n - 1
		p = 1;
		for (j = 0; j < n; j++) {  //for every value of counter we calculate which combination of prime number it represents

			// Check if jth bit in the
			// counter is set If set
			// then multiply jth element from set
			if (counter & (1 << j)) {
				p *= a[j];
			}
		}

		// if number of bits in counter is odd, means it p is a combination of odd number of prime numbers
		if (__builtin_popcount(counter) & 1) //__builtin_popcount returns number of set bit in  counter
			odd += (m / p);
		else
			even += (m / p);
	}

	return odd - even;
}

// Driver Code
int main()
{
	int a[] = { 2, 3, 5, 7 };
	int m = 100;
	int n = sizeof(a) / sizeof(a[0]);
	cout << count(a, m, n);
	return 0;
}
