#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int pos = 0, a;

    for (;;pos++) {
        cin >> a;
        if (a == 1) break;
    }

    int x = pos % 5;
    int y = pos / 5;

    cout << abs(x - 2) + abs(y - 2) << endl;

    return 0;
}