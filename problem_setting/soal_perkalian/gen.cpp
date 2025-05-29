#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    
    int n = rnd.next(1, 1000000);
    cout << n << '\n';
    for(int i = 0; i < n; i++){
      cout << rnd.next(-1000000000, 1000000000) << '\n';
    }
}
/*
<#list 1..50 as testNumber>
    gen test_dulu_ngab ${testNumber} > $
</#list>

5 12
3 8 4 2 5


4 8
10 13 9 25

<#list 1..50 as testNumber>
    gen test_dulu_ngab ${testNumber} > $
</#list>



    const int N = 2e5, A = 1e9;

    int roll_high=rnd.next(1,200);
    int n;

    if(roll_high % 5 <= 1){
      n = rnd.next(N/2, N);
    }
    else n = rnd.next(1, N);

    int x = rnd.next(1, A);
    cout << n << ' ' << x << '\n';
    for(int i = 0; i < n; i++){
      cout << (roll_high % 5 <= 1 ? rnd.next(A/2, A) : rnd.next(1, A)) << (i == n - 1 ? "\n" : " ");
    }
*/