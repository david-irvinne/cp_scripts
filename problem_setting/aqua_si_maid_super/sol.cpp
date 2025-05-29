#include<bits/stdc++.h>
using namespace std;

#define int long long
// #define Int __int128_t
#define dbg(x) cout<<"["<< #x <<"] : "<<(x)<<endl;
#define bpc(x) (__builtin_popcountll(x))

int bpow(int a, int b, long long mod=LLONG_MAX){
	int res=1;while(b){if(b%2)res=res*a%mod;a=a*a%mod;b/=2;}return res;
}
int inv(int a, int mod=1e9+7){ return bpow(a, mod-2, mod); }

void doumo_same_desu(){	
  int n;
  cin >> n;
  vector<int> H(n);
  for(int i = 0; i < n; i++){
    cin >> H[i];
  }
  sort(H.begin(), H.end());

  int q;
  long long res = 0;
  cin >> q;
  while(q--){
    int x;
    cin >> x;

    int p = -1;
    for(int J = 1 << 30; J; J /= 2){
      if(p + J < n && H[p + J] <= x) p += J;
    }
    if(p == -1) continue;
    res += H[p];
  }
  cout << res << '\n';
}   
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

	int tc = 1;
	// cin >> tc;
	while(tc--) doumo_same_desu();
}
/*

*/

