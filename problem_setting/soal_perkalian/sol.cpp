#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
  cin >> n;
  long long res = 1;
  const long long mod = 1e9 + 7;
  while(n--){
    long long x; cin >> x;
    res *= x;
    res %= mod;
  }
  while(res < 0) res += mod;
  res %= mod;
  cout << res << '\n';
}