#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

 void multiply(vector<int>&number, int x){

 	int carry = 0;
 	for(int i=0;i<number.size();i++){

 		int a = number[i]*x + carry;
 		carry = a/10;
 		number[i] = a%10;
 	}

 	while(carry){
 		number.push_back(carry%10);
 		carry = carry/10;
 	}

 }
int main() {
	int n;
	cin>>n;

	vector<int>number;
	number.push_back(1);

	for(int i=2;i<=n;i++)
		multiply(number,i);

	reverse(number.begin(),number.end());

	for(int i=0;i<number.size();i++)
		cout<<number[i];
	return 1;
}