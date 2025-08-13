// https://lightoj.com/problem/investigation
#include<bits/stdc++.h>
using namespace std;


void doumo_same_desu(); int TC, ALLTC;
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(5);

	cin >> ALLTC; for(TC=1;TC<=ALLTC;TC++){
    cout << "Case " << TC << ": ";
    doumo_same_desu();
  }
}
// in range l, r how many number that divisible by k and 
// the sum of its digits is also divisible by k

int dp[10][99][2][99];
vector<int>digits;
int k;
int l, r;

// current actual number, current digit sum
int f(int idx, int cur, bool tight, int sum){
  if(idx == (int)digits.size()){
    return cur % k == 0 && sum % k == 0;
  }
  if(dp[idx][cur][tight][sum] != -1) return dp[idx][cur][tight][sum]; 

  int res = 0, limit = tight ? digits[idx] : 9;
  for(int i = 0; i <= limit; i++){
    res += f(idx + 1, (cur*10 + i) % k, tight && i == limit, (sum + i) % k);
  }
  return dp[idx][cur][tight][sum] = res;
} 


int solve(int x){
  if(k > 90) return 0;
  memset(dp, -1, sizeof(dp));
  digits.clear();
  if(x == 0) digits.push_back(0);
  while(x > 0){
    digits.push_back(x % 10);
    x /= 10;
  }

  reverse(digits.begin(), digits.end());
  return f(0, 0, true, 0 );
}

void doumo_same_desu(){
  cin >> l >> r >> k;
  cout << solve(r) - solve(l - 1) << '\n';
}

/*

*/
