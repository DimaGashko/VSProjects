#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int *arr;
string res;
string s;

void run(char side, int l, int r, int prev) {
    int cur = (side == 'L') ? arr[l] : arr[r];

    if (cur > prev && l <= r) {
        s.push_back(side);

        int newL = (side == 'L') ? l + 1 : l;
        int newR = (side == 'L') ? r : r - 1;

        if ((arr[l + 1] < arr[r] && arr[l + 1] > arr[l]) || l + 1 > r) {
            run('L', newL, newR, cur);
        }

        if ((arr[r] < arr[l + 1]  && arr[r] > arr[l + 1]) || l + 1 > r) {
            run('R', newL, newR, cur);
        }

        s.pop_back();

    }

    if (s.length() > res.length()) {
        res = string(s.begin(), s.end());
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;

    arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    s.reserve(200000);
    run('L', 0, n - 1, -1);

    if (arr[0] >= arr[n - 1]) {
        run('R', 0, n - 1, -1);
    }

    cout << res.length() << endl << res << endl;

    return 0;
}