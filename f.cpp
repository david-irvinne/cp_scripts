// created at: 2026-05-16 15:44:31
#include<bits/stdc++.h>
#include <climits>
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
  int n;
  cin >> n;
  vector<int>ar;
  ar.push_back(0);
  for(int i = 0; i < n; i++){
    int x; cin >> x; ar.push_back(x);
  }
  sort(ar.begin(), ar.end());
  
  int start = 0;
  for(int i = 0; i <= n; i++) {
    if(ar[i] == 0) {
      start = i;
      break;
    }
  }

  int L = start - 1, R = start + 1;
  int currentPosition = 0, res = 0;
  while(L >= 0 || R <= n){
    int jarak_ke_kiri = LLONG_MAX, jarak_ke_kanan = LLONG_MAX;
    if(L >= 0) jarak_ke_kiri = abs(currentPosition - ar[L]);
    if(R <= n) jarak_ke_kanan = abs(currentPosition - ar[R]);

    if(jarak_ke_kiri <= jarak_ke_kanan) {
      res += jarak_ke_kiri;
      currentPosition = ar[L];
      L--;
    }
    else {
      res += jarak_ke_kanan;
      currentPosition = ar[R];
      R++;
    }
  }

  cout << res << '\n';
}

/*

*/
