#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();

    int n, prev, res = 1;
    cin >> n >> prev;

    for (int i = 1; i < n; i++) {
        int next;
        cin >> next;

        if (next != prev) {
            res++;
            prev = next;
        }
    }

    cout << res << endl;

    return 0;
}