#include <bits/stdc++.h>
using namespace std;

#define int long long

int q, k;
int maxn = 2e5 + 5;
signed main(){
    cin >> q >> k;
    set<int> emp;
    // mexnya ga mungkin ampe 1e9
    for(int i = 0; i <= maxn; i++) emp.insert(i);
    while(q--){
        int x;
        cin >> x;
        auto it = emp.find(x);
        if(it == emp.end() and x <= maxn){
            emp.insert(x);
        }else if(x <= maxn) emp.erase(it);
        int mexs = *emp.begin();
        int res = 0;
        bool ok = 1;
        for(int i = 30; i >= 0; i--){
            int bm = (mexs >> i) & 1;
            int bk = (k >> i) & 1;
            if(ok){
                if(bk == 0){ 
                    if(bm) res = res | (1 << i);
                }
                else ok = bm == 1;
            }
        }
        cout << res << endl;
    }



}
