#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int n, p, k;
    cin >> n >> p >> k;

    string res;

    if (p - k > 1) res += "<< ";

    for (int i = max(p - k, 1); i <= min(p + k, n); i++) {
        string cur = (i == p) ? "("+ to_string(i) + ")" : to_string(i);
        res += cur + " ";
    }

    if (p + k < n) res += ">>";

    cout << res << endl;

    return 0;
}