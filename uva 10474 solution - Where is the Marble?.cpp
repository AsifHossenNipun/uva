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



int m = 0;

int main()
{
    while(1){
    	int x, y;
    	m++;
    	cin >> x >> y;
    	if(x == 0 && y == 0) break;
    	vector <int> v;
    	int n;
    	for(int i = 0; i < x; i++){
    		
    		cin >> n;
    		v.pb(n);

    	}
    	sort(all(v));
    	cout << "CASE# " << m << ":" << endl;
    	for(int i = 1; i <= y; i++){
    		cin >> n;
    		if(binary_search(v.begin(), v.end(), n)){
    			vector<int>::iterator p = lb(v.begin(), v.end(), n);
    			cout << n << " found at " <<  p - v.begin() + 1 << endl;
    		}
    		else cout << n << " not found" << endl;
    	}
    }
    return 0;
}
