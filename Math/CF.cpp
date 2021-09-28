#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#define ll long long int
using namespace std;

int main()
{
	/* code */
	int t;
	cin>>t;

	while(t--){
		string s;

		cin>>s;
		int n = s.length();

		int a=0,b=0,c=0,i;
		for(i=0;i<n;i++){
				if(s[i] == 'A')
					a++;
				else if(s[i] == 'B')
					b++;
				else if(s[i]=='C')
					c++;
				else{
					cout<<"NO"<<endl;
					break;
				}
		}

		if(i!=n)
		{
			continue;
		}

		if( b == a+c)
		{
			cout<<"YES"<<endl;
		}else
				cout<<"NO"<<endl;

	}
	return 0;
}