#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int run1() {
    int c, m, x, res;
    cin >> c >> m >> x;

    if (c > m) swap(c, m);

    x += m - c;

    res = min(c, x);

    if (x != res) {
        return res;
    }

    c -= res;
    m -= res;

    if (c > m) swap(c, m);

    int d = min(c, m / 2);
    res += d;

    c -= d;
    m -= d * 2;

    if (c == 0) {
        return res;
    }

    if (c > m) swap(c, m);

    int d2 = min(c, m / 2);
    res += d2;

    return res;
}

int run() {
    int c, m, x, res = 0;
    cin >> c >> m >> x;

    int d1 = min(c, min(m, x));

    res += d1;

    c -= d1;
    m -= d1;

    if (c <= 0 || m <= 0) {
        return res;
    }

    if (c > m) swap(c, m);

    int d = min(c, m / 2);
    res += d;

    c -= d;
    m -= d * 2;

    if (c == 0) {
        return res;
    }

    if (c > m) swap(c, m);

    int d2 = min(c, m / 2);
    res += d2;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << run() << endl;
    }

    return 0;
}



// A
//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//map<int, int> m;
//
//bool canGet(int n) {
//    if (m[n] >= 1) {
//        m[n]--;
//        return true;
//
//    }
//
//    if (n == 1) {
//        return false;
//    }
//
//    return canGet(n / 2) && canGet(n / 2);
//}
//
//string run() {
//    m.clear();
//
//    int n;
//    cin >> n;
//
//    for (int i = 0; i < n; i++) {
//        int c;
//        cin >> c;
//
//        m[c]++;
//    }
//
//    return (canGet(2048) ? "YES" : "NO");
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie();
//    cout.tie();
//
//    int n;
//    cin >> n;
//
//    for (int i = 0; i < n; i++) {
//        cout << run() << endl;
//    }
//
//    return 0;
//}
//
//
