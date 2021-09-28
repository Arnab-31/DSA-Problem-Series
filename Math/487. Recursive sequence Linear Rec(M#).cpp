//https://www.spoj.com/problems/SEQ/
//Following the same apporach of the prevous problem

#include<iostream>
#include<vector>
#define REP(i,n) for (int i = 1; i<= n; i++)
using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000000;
int K = 2;

// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K+1, vector<ll>(K+1));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

// computes A ^ p
matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

// returns the N-th term of Fibonacci sequence
int solve(int K,ll b[], ll c[], ll n)
{
    // create vector F1
    vector<ll> F1(K+1);
    REP(i, K)
    	F1[i] = b[i-1];

    // create matrix T
     matrix T(K+1, vector<ll>(K+1));

     REP(i, K){
     	REP(j, K){
     		if(i==K)
     			T[i][j] = c[K-j];
     		else if(j == i+1)
     			T[i][j] = 1;
     		else
     			T[i][j] = 0;
     	}
     } 
     // raise T to the (N-1)th power
     if (n <= K)
         return b[n-1];

     T = pow(T, n-1);

         // the answer is the first row of T . F1
     ll res = 0;
     REP(i, K)
         res = (res + T[1][i] * F1[i]) % MOD;
    return res;
}


int main(){
	int t;
	cin>>t;

	while(t--){
		int k;
		cin>>k;
		K = k;

		ll b[k],c[k];

		REP(i,k)
			cin>>b[i-1];
		REP(i,k)
			cin>>c[i-1];

		ll n;
		cin>>n;

		ll ans = solve(k,b,c,n);

		cout<<ans<<endl;
	}
	
	return 0;
}