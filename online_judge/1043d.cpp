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

int bpow(int a, int b, int mod = LLONG_MAX) {
	int res=1;while(b){if(b%2)res=res*a%mod;a=a*a%mod;b/=2;}return res;
}
int inv(int a, int mod=1e9+7){ return bpow(a, mod-2, mod); }

void doumo_same_desu(); int TC, ALLTC;
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

	cin >> ALLTC; for(TC=1;TC<=ALLTC;TC++)
  doumo_same_desu();
}
int k;

int f(int n){
  // 1234567....n
  // hitung panjang bilangan ini

  int mx_len = to_string(n).size();
  int total = 0;
  for(int len = 1; len < mx_len; len++){
    total += len *  9ll * bpow(10ll, len - 1);
    if(total > (int)1e15) return LLONG_MAX;
  }
  
  total += mx_len * (n - bpow(10ll, mx_len - 1) + 1);
  return total ;
}

int sum_digits_1_to_n(int  n) {
  if (n <= 0) return 0;
  Int total = 0;
  Int p = 1;
  Int N = n;
  while (p <= N) {
    Int left = N / (p * 10);
    int cur = (int)((N / p) % 10);
    Int right = N % p;

    total += left * 45 * p;
    total += (Int)(cur) * (cur - 1) / 2 * p;
    total += (Int)cur * (right + 1);

    p *= 10;
  }
  return (int)total;
}

void doumo_same_desu(){
  cin >> k;

  // cari bilangan bulat h terbesar sehingga 12345....h memiliki digit kurang dari sama dengan k
  int h = 0;
  for(int J = 1ll << 60; J; J /= 2){
    if(f(h + J) <= k) h += J;
  }

  // hitung penjumlahan digit 1234....h
  int sum = sum_digits_1_to_n(h);

  // ambil sisanya
  if(f(h) != k){
    int len = k - f(h);
    string tmp = to_string(h + 1);
    for(int i = 0; len--; i++) sum += tmp[i] - '0';
  }
  cout << sum << '\n';
}

/*

*/
