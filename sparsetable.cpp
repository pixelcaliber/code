#include <bits/stdc++.h>
using namespace std;
#define endl        '\n'
#define F           first
#define S           second
#define ld          double
#define sz(x)       x.size()
#define ll          long long
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define maxe(a)     max_element(all(a))
#define mine(a)     min_element(all(a))
#define vin(a)      ll x; cin >> x; a.pb(x);
#define loop(i,x,y) for(int i = x; i < y; i++) 

typedef vector<ll> vll;           typedef map<ll, ll> mapl;
typedef vector<pair<ll, ll>> vpl;
ll n;
const ll mod = 1e9 + 7, N = 2e5 + 2, K = 25;
/**
 * WHAT AM I LEARNING?
 * 		SAPRSE TABLE.

 * WHY AM I LEARNING THIS?
 * 		TO ANSWER RANGE QUERY PROBLEMS VERY FAST AND EFFICIENTLY.

 * WHAT'S THE INTUTION?
 * 		PREPARE A TABLE OR A MATRIX TO STORE THE REQUIRED RESULTS FOR SOME INTERVALS IMP THING TO NOTIC IS THAT 
 * 		WE ARE NOT INTERESTED IN ALL INTERVALS BUT ONLY FEW THAT'S WHHY ITS CALLED SPARSE TABLE
 * 		AND THEN USE THOSE STORED VALUES TO ANSWER EACH QUERY.
 * 
 * WHAT INTERVALS U ARE TALKING ABOUT? PLEASE ELABORATE.
 * 		SPARSE TABLE WILL STORE ANSWERS FOR EACH INTERVALS HAVING LENGTH EQUALS POWER OF 2.
 * 
 * WHY THIS WORKS?
 * 		AS WE KNOW THAT EVERY NUMBER CAN BE REPRESENTED IN POWERS OF 2 IT'S BINARY RERESENTATION, 
 * 		SO WE WILL USE THIS FACT AND OUR TABLE WILL BE TARGETING THESE INTERVALS WHICH LATER CAN BE SUMMED UP TO GET 
 * 		THE ANSWER OF ANY BIGGER OR DIFFERENT INTERVAL.
 * 
 * HOW TO PREPARE THIS TABLE? AND WHAT'S THE TIME COMPLEXITY OF THE PRROCESS?
 * 		BUILD A 2D ARRAY OF SIZE N*(LOGN + 1) WHERE [i][j] HAS ANSWER FOR THE RANGE [i, i + 2^j - 1]
 * 		WE WILL KEEP ON INCREMENTING THE J FROM 0 TO LOGN AND THUS FOR EVERY RANGE OF LENGTH POWER OF 2 
 * 		WE WILL GET OUR ANSWER. 
 * 		THE BEST WAY TO DO THIS IS USE DP AS WE CAN SEE THE RANGE i, i + 2^j - 1 CAN BE WRITTEN AS
 * 		[i, i + 2^(j - 1)], [i + 2^(j - 1), i + 2^j - 1] BTIH RANGES HAVE LENGTH OF 2^(j - 1) I.E PREVIOUS
 * 		POWER OF 2 THUS USING THIS REALATION -- 
 * 		WE MOVE IN POWERS OF 2 AND COMPUTE EACH LARGER LEN RANGE USING 2 SMALLER RANGES WHICH ARE ALREADY 
 * 		COMPUTED.
 * 		for j in range 0 to logN.
 * 			for i in range 0 to n
 *		 		table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]).
 * 		TC = O(N * log(n));
 * 
 * HOW WE USE OUR TABLE TO ANSWER QUERIES?
 * 		WE CHANGE OUR INTERVAL OF LENGTH SAY R - L + 1 INTO POWERS OF 2 AND CHECK FOR THE RESULTS OF THOSE
 * 		INTERVALS FROM OUR TABLE THEN WE COMBINE THEM TO GET OUR FINAL RESULT
 * 		TO CHANGE R - L + 1 IN POWERS TO 2 WE CAN GO FOR TC OF LOG(R - L + 1) OR ALSO POSSIBLE IN O(1)
 * 		SO, j = log[R - L + 1];
 * 		minimum = min(table[L][j], table[R - (1 << j) + 1][j])
 * 		
 * 		T.C. == O(N * logn + Q);
 * */

											//RANGE MINIMUM QUERY..

// ll table[N + 1][K + 1];
// ll binary_log[N];
// void precompute_logs(){
// 	 binary_log[1] = 0;
// 	 for (int i = 2; i < N; ++i)
// 		binary_log[i] = binary_log[i / 2] + 1;			//PRECOMPUTATION..
// }
// int main()
// {
// 	   precompute_logs();
// 	   cin>>n;
//     vll a;
//     int q;cin>>q;
//    	for (int i = 0; i < n; ++i)
//    	{
//    		vin(a);										//PRECOMPUTATION..
//    	}

//    	for (int i = 0; i < n; ++i)
// 		table[i][0] = a[i];

// 	for (int j = 1; j <= K; ++j)
// 		for(int i = 0; i + (1LL << j) <= n; i++)
// 			table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
// 	while(q--){
		
// 		ll L, R;cin>>L>>R;
// 		ll j = binary_log[R - L + 1];
// 		// ll j = __lg(R - L + 1);
// 		ll minimum = min(table[L][j], table[R - (1 << j) + 1][j]);
// 		cout<<minimum<<endl;
// 	}
// }
							//RANGE SUM QUERIES... T.C - O(N*logN + q*logN)
ll table[N + 1][K + 1];

int main(){

	cin>>n;
    int q;cin>>q;
   	vll a;
   	for (int i = 0; i < n; ++i)
   	{
   		vin(a);										  //PRECOMPUTATION..
   	}

   	for (int i = 0; i < n; ++i)
		table[i][0] = a[i];

	for (int j = 1; j <= K; ++j)
		for(int i = 0; i + (1LL << j) <= n; i++)
			table[i][j] = table[i][j - 1] + table[i + (1LL << (j - 1))][j - 1];
	
	while (q--){

		ll L, R, sum = 0;cin>>L>>R;
        L--, R--;

	    for (int i = K; i >= 0; --i)
		{
			if ((1LL << i) <= R - L + 1)
			{
				sum += table[L][i];
				L += (1LL << i);
			}
		}
		cout<<sum<<endl;
	}
}