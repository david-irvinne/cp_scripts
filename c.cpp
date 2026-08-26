// created at: 2026-08-22 18:05:20
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

//	cin >> ALLTC; for(TC=1;TC<=ALLTC;TC++)
  doumo_same_desu();
}

void doumo_same_desu(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<int>ar;
  vector<bool> makan(n); // pernah makan di hari ke-i = {true, false}
  int cur = 0;
  for(int i = 0; i < n; i++){
    if(i - m >= 0 && makan[i - m]) cur -= ar[i - m];

    int x;
    cin >> x;
    ar.push_back(x);

    if(cur + x <= k){
      cout << "Yes\n";
      cur += x;
      makan[i] = true;
    }
    else cout << "No\n";
    // cout << "i: " << cur << '\n';

  }
  cout << '\n';
}

/*

*/
