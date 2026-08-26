#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
vector<int> ar, prf, suf; // range sum, prefix min, suffix min

int get_range_sum(int l, int r){
  return ar[r] - ar[l-1];
}

const int INF = 1e12;

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n >> k;
  ar.resize(n + 5);
  prf.resize(n + 5);
  suf.resize(n + 5);
  for(int i = 1; i <= n; i++) {
    cin >> ar[i];
    suf[i] = prf[i] = ar[i];
    if(i > 1) prf[i] = min(prf[i], prf[i-1]);
    if(i > 1) ar[i] += ar[i-1];
  }
  for(int i = n - 1; i >= 1; i--) suf[i] = min(suf[i], suf[i+1]);

  int res = -INF;
  // for(int i = 1; i <= n; i++){
  //   cout << ar[i] << ' ' << prf[i] << ' ' << suf[i] << '\n';
  // }

  for(int l = 1; l + k - 1 <= n; l++){
    int left_len = l - 1, right_len = n - (l + k - 1);
    // cout << left_len << ' ' << right_len << '\n';
    int mid = get_range_sum(l, l + k - 1);
    int left = prf[l - 1] * left_len - left_len * (left_len + 1) / 2;
    int right = suf[l + k] * right_len - right_len * (right_len + 1) / 2;

    // cout << left << ' ' << mid << ' ' << right << '\n';
    res = max(res, left + mid + right);
  }
  cout << res << '\n';
}


/*
6 2
2 4 5 3 1 6
*/
