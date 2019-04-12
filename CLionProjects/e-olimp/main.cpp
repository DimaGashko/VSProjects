#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, res = 0;
    cin >> n;

    for (; n != 0; n >>= 1) res++;
    cout << res << endl;

    return 0;
}