// https://www.spoj.com/problems/CPCRC1C/
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

void doumo_same_desu(int l, int r); int TC, ALLTC;
signed main(){
  //	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

  while(1) {
    int l, r;
    cin >> l >> r;
    if(l == -1 && r == -1) break;
    doumo_same_desu(l, r);
  }
}
vector<int> digits;

int memo[11][2][9 * 11];

int dp(int idx, bool tight, int sum){
  if(idx == (int)digits.size()){
    return sum;
  }

  if(memo[idx][tight][sum] != -1) return memo[idx][tight][sum];

  int limit = tight ? digits[idx] : 9;
  int res = 0;
  for(int i = 0; i <= limit; i++){
    res += dp(idx + 1, tight && i == limit, sum + i);
  }
  return memo[idx][tight][sum] = res;
}

int solve(int x){
  memset(memo, -1, sizeof(memo));
  digits.clear();
  if(x == 0){
    digits.push_back(0);
  } while(x > 0){
    digits.push_back(x % 10);
    x /= 10;
  }
  reverse(digits.begin(), digits.end());

  return dp(0, true, 0);
}

void doumo_same_desu(int l, int r){
  cout << solve(r) - solve(l-1) << '\n';
}

/*

*/
