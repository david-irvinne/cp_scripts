#include <bits/stdc++.h>
using namespace std;

int x, y, a[15], b[15];

int jarak(int n, int m) {
    return abs(n) + abs(m);
}

int pangkat(int n, int m) {
	if(m == 0){
		return 1;
	}
    return n * pangkat(n, m - 1);
}

bool run(int n, int m, int k, string &t) {
    if (n == 0 && m == 0 && k == -1) {  //sudah mencapai titik awal
        return true;
    }
    if (k < 0) {
        return false;  //tidak bisa mencapai titik awal
    }

    int step = a[k];

    if (jarak(n - step, m) <= b[k - 1]) {
        t += 'R';
        if (run(n - step, m, k - 1, t)) return true;
        t.pop_back();
    }

    if (jarak(n, m - step) <= b[k - 1]) {
        t += 'U';
        if (run(n, m - step, k - 1, t)) return true;
        t.pop_back();
    }

    if (jarak(n + step, m) <= b[k - 1]) {
        t += 'L';
        if (run(n + step, m, k - 1, t)) return true;
        t.pop_back();
    }

    if (jarak(n, m + step) <= b[k - 1]) {
        t += 'D';
        if (run(n, m + step, k - 1, t)) return true;
        t.pop_back();
    }

    return false;
}

int main() {
    b[0] = 1;
    for (int i = 0; i <= 14; i++) {
        a[i] = pangkat(2, i);
        if (i != 0) {
            b[i] = b[i - 1] + a[i];
        }
    }

    cin >> x >> y;

    int steps = 0;
    while (jarak(x, y) > b[steps]) {
        steps++;
    }

    if (steps > 14) {
        cout << -1 << endl;
        return 0;
    }

    string ans;
    if (run(x, y, steps, ans)) {
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}