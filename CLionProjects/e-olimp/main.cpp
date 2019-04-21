#include <bits/stdc++.h>

using namespace std;

#define IO_HACK ios_base::sync_with_stdio(false); cin.tie(); cout.tie();
#define endl "\n"

int main() {
    IO_HACK

    int n, max = 1000000001;
    long long res = 0;
    cin >> n;

    vector<int> arr(n);

    for (auto &item : arr) {
        cin >> item;
    }

    for (int i = n - 1; i >= 0 && max != 0; i--) {
        max = min(max, arr[i]);
        res += max--;
    }

    cout << res << endl;

    return 0;
}