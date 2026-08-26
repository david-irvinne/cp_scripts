#include <bits/stdc++.h>
using namespace std;

#define int long long
string s[1010];
int n, m;

int dx[4] = {0, 1, 1, 0};
int dy[4] = {0, 1, 0, 1};

bool cek(int x, int y){
    int sum = 0;
    //cout << "cur : " << x << ' ' << y << endl;
    for(int k = 0; k < 4; k++){
        int nx = dx[k] + x;
        int ny = dy[k] + y;
        //cout << nx << ' ' << ny << endl;
        sum += s[nx][ny] == '.';
    }
    return (sum == 3);
}
bool ok(int x, int y){
    if(x >= 0 and x < n - 1 and y >= 0 and y < m - 1) return 1;
    return 0;
}
signed main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            cnt += cek(i, j);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        vector<pair<int,int>> tocek;
        if(ok(r, c)) tocek.push_back({r, c});
        if(ok(r - 1, c)) tocek.push_back({r - 1, c});
        if(ok(r, c - 1)) tocek.push_back({r, c - 1});
        if(ok(r - 1, c - 1)) tocek.push_back({r - 1, c - 1});
        for(auto[a, b] : tocek){
            // cout << a << ' ' << b << endl;
            cnt -= cek(a, b);
        }
        if(s[r][c] == '#') s[r][c] = '.';
        else s[r][c] = '#';
        for(auto[a, b] : tocek){
            cnt += cek(a, b);
        }
  }
}
        
