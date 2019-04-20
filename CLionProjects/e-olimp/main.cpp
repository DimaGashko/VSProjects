#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int next;
        cin >> next;

        if (next == 1) {
            cout << "HARD" << endl;
            return 0;
        }
    }

    cout << "EASY" << endl;

    return 0;
}