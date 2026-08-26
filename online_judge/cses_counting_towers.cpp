#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
#define Int __int128_t
 
#ifdef DEBUG
#define dbg(x) cout << "["<< #x <<"] : "<< (x) <<endl;
#else
#define dbg(x)
#endif
 
int bpow(int a, int b, int64_t mod = LLONG_MAX) {
	int res=1;while(b){if(b%2)res=res*a%mod;a=a*a%mod;b/=2;}return res;
}
int inv(int a, int mod=1e9+7){ return bpow(a, mod-2, mod); }
 
void doumo_same_desu(); int TC, ALLTC;
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);
 
	// cin >> ALLTC; for(TC=1;TC<=ALLTC;TC++)
  doumo_same_desu();
}
 
void doumo_same_desu(){
  const int MOD = 1e9 + 7;
  int n = 1e6 + 2;
 
  vector<int> one(n + 2), two(n + 2);
  one[1] = two[1] = 1;
  for(int i = 2; i <= n; i++){
    one[i] = 2 * one[i-1] + two[i-1];
    two[i] = 4 * two[i-1] + one[i-1];
    one[i] %= MOD;
    two[i] %= MOD;
  }
 
  int t; cin >> t; while(t--){
    int x; cin >> x; cout << (one[x] + two[x]) % MOD << '\n';
  }
}
 
/*
 
*/
