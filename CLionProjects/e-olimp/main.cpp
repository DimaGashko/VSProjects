#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

string run(int n) {
    if (n % 4 == 1) return "0 A";
    if (n % 4 == 3) return "2 A";
    if (n % 4 == 2) return "1 B";
    if (n % 4 == 0) return "1 A";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    cout << run(n) << endl;

    return 0;
}
