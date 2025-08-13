//https://lightoj.com/problem/palindromic-numbers
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define Int __int128_t
#define bpc(x) __builtin_popcountll(x)
#define msb(x) (63-__builtin_clzll(x))

#ifdef DEBUG
#define dbg(x) cout<<"["<< #x <<"] : "<<(x)<<endl;
#else
#define dbg(x)
#endif

int bpow(int a, int b, long long mod=LLONG_MAX){
	int res=1;while(b){if(b%2)res=res*a%mod;a=a*a%mod;b/=2;}return res;
}
int inv(int a, int mod=1e9+7){ return bpow(a, mod-2, mod); }

void doumo_same_desu(); int TC, ALLTC;
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

	cin >> ALLTC; for(TC=1;TC<=ALLTC;TC++) {
    cout << "Case " << TC << ": ";
    doumo_same_desu();
  }
}

int solve(int x){
  if(x <= 10) return min(x + 1, 10ll);
  // 0 sampe 9 ada 10
  // 11 sampe 99 ada 9
  // 101 sampe 999 ada 90
  // 1001 sampe 9999 ada 90
  // 10001 sampe 99999 ada 900
  // 100001 sampe 999999 ada 900
  
  int len = to_string(x).size();
  string s = to_string(x);
  if(x % 10 == 0) {
    s = to_string(x - 1);
    len = s.size();
  }
  //dbg(len);
  
  int res = 10;
  for(int l = 2, add = 9; l < len; l++){
    if(l % 2) add *= 10;
    res += add;
  }
  //dbg(res);

  for(int i = len - 1,  pp= 0; i > len / 2; i--, pp++){
    if(s[i] < s[len - i - 1]){
      x -= (s[i] - '0' + 1) * bpow(10ll,pp);
      dbg((s[i] - '0' + 1) * bpow(10ll,pp));
      s = to_string(x);
    }
  }

  //dbg(s);

  res += stoll(s.substr(0, (len+1)/2));
  res -= bpow(10ll, (len + 1) / 2 - 1) - 1;
  return res;
}

void doumo_same_desu(){
  int L, R;
  cin >> L >> R;
  if(L > R) swap(L, R);
  cout << solve(R) - solve(L - 1) << '\n';
}

/*

*/
