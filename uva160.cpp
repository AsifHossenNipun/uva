#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
#define mp make_pair
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define resz resize
using namespace std;
const int mod = 10000007;


int t,x, y, z, m, l, f;
vector<int> vec[101];
bool prime[101];
void prim(int n) 
{ 
     memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is true then p is a prime 
        if (prime[p] == true) 
        {  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
   
}
void divisors(int n){
	int d = n;
	while(n%2==0){
		vec[d].pb(2);
		n /= 2;
	}
	for(int i = 3; i <= sqrt(n); i+=2){
		while(n%i == 0){
			vec[d].pb(i);
			n /= i;
		}
	}
	if(n > 1) vec[d].pb(n);
}


void solve(){
	
	//vector <int> v;
	
	vec[2].pb(2);
  
    FOR(i,3,101){
    	for(int j = 0; j < vec[i-1].size(); j++){
    		int au = vec[i-1][j];
    		vec[i].pb(au);
    	}
    	if(prime[i])vec[i].pb(i);
    	else{
    		divisors(i);
    	}
    }
}



int main()
{
    solve();
    prim(101);
    vector<int> ve;
    for(int i = 2; i < 101; i++){
    	if(prime[i]) ve.pb(i);
    }
    while(1){
    	int in;
	    cin >> in;
	    if(in == 0) break;
	    multiset<int> s;
	    for(int i = 0; i < vec[in].size(); i++){
	    	int xs = vec[in][i];
	    	s.insert(xs);
	    }
	    int cnt = 0;
	    printf("%3d", in);
	    cout << "! =";
	    for(int i = 0; i < ve.size(); i++){
	    	int pu = s.count(ve[i]);
	    	if(pu > 0){
	    		printf("%3d", pu);
	    		cnt++;
	    		if(cnt == 15) cout << endl << "      ";
	    	}
	    }
	    cout << endl;
    }
    return 0;
}