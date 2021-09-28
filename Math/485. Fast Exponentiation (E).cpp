#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define mod 10000007
 int power(int n, int x){

 	if(x==0)
 		return 1;

 	long long int p = power(n,x/2);

 	if(x%2==0)
 			return (p * p)% mod;
 	else
 			return (n * p * p)%mod;
 }


int main() {
	int n,x;
	cin>>n>>x;

	cout<<power(n,x);
	return 1;
}