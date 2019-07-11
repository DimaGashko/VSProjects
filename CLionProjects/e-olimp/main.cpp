#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

char get(int x, int y, int z) {
    if (x == y && z == 0) return '0';
    if (x > y + z) return '+';
    if (y > x + z) return '-';

    return '?';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int x, y, z;
    cin >> x >> y >> z;

    cout << get(x, y, z) << endl;
    return 0;
}
