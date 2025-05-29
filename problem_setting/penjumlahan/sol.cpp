#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
  int n;
  cin >> n;

  map<string, int> p;
  p["senin"] = 1;
  p["selasa"] = 2;
  ...
  p["minggu"] = 7;

  int hasil = 0;
  while(n--){
    string hari; cin >> hari;
    hasil += p[hari];
  }
  cout << hasil;
}